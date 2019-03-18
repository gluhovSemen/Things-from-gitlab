#include <stdio.h>
#include <dos.h>
#include <mem.h>
#include <conio.h>

struct ProcStats //struktura soderjashaya kontext zadachi
{
    unsigned int rax, rbx, rcx, rdx; // 0  2  4  6
    unsigned int rsi, rdi, rbp, rsp; // 8 10 12 14
    unsigned int rcs, rds, res, rss; //16 18 20 22
    unsigned int rip, rflags, a, b;  //24 26 28 30
} Stats[2]; //massiv iz treh takih struktur

unsigned int current_proc; //nomer tekushey zadachi
unsigned int stats_offset; //adres konteksta zadachi
int x;

void interrupt (*oldHandler)(...); //ukazatel na staryi obrabotchik preryvaniya

void interrupt IntHandler(...) //svoy obrabotchik
{
		asm {
	mov  si, [current_proc]; //nomer procedury
	mov  cl, 5 //umnojaem nar 32 (razmer struktury)
	shl  si, cl
	//mov  ax, offset Stats
	mov  ax, [stats_offset] //pribavlyaem adres nachala massiva struktur
	add  si, ax  //poluchaem adres nujnogo konteksta
	pop  ax      //zapisyvaem v nego registry
	mov  [si+12], ax  //bp
	pop  ax
	mov  [si+10], ax  //di
	pop  ax
	mov  [si+ 8], ax  //si
	pop  ax
	mov  [si+18], ax  //ds
	pop  ax
	mov  [si+20], ax  //es
	pop  ax
	mov  [si+ 6], ax  //dx
	pop  ax
	mov  [si+ 4], ax  //cx
	pop  ax
	mov  [si+ 2], ax  //bx
	pop  ax
	mov  [si+ 0], ax  //ax
	pop  ax
	mov  [si+24], ax  //ip
	pop  ax
	mov  [si+16], ax  //cs
	pop  ax
	mov  [si+26], ax  //flags
	mov  ax, sp
	mov  [si+14], ax  //sp
	mov  ax, ss
	mov  [si+22], ax  //ss

	mov  ax, [current_proc] //perehodim k sleduyushey zadache
	inc  ax
	cmp  ax, 2
	jb label1
	mov  ax, 0
		}
		label1:
		asm {
	mov  [current_proc], ax //vychislyaem adres eyo konteksta
	mov  si, ax
	mov  cl, 5
	shl  si, cl
	//mov  ax, offset Stats
	mov  ax, [stats_offset]
	add  si, ax       //zagrujaem registry
	mov  ax, [si+22]  //ss
	mov  ss, ax
	mov  ax, [si+14]  //sp
	mov  sp, ax
	mov  ax, [si+26]  //flags
	push ax
	mov  ax, [si+16]  //cs
	push ax
	mov  ax, [si+24]  //ip
	push ax
	mov  ax, [si+ 0]  //ax
	push ax
	mov  ax, [si+ 2]  //bx
	push ax
	mov  ax, [si+ 4]  //cx
	push ax
	mov  ax, [si+ 6]  //dx
	push ax
	mov  ax, [si+20]  //es
	push ax
	mov  ax, [si+18]  //ds
	push ax
	mov  ax, [si+ 8]  //si
	push ax
	mov  ax, [si+10]  //di
	push ax
	mov  ax, [si+12]  //bp
	push ax
		}
		oldHandler(); //vyzyvaem staryi obrabotchik
}

void Proc1(void);
void Proc2(void);


int main(void)
{
		unsigned int i, rd, rc, re, rs, ri0, ri1, f;

		for(i=0;i<2;i++)
	memset(&Stats[i],0,sizeof(ProcStats));
		asm {   //zapisyvaem registry vo vremennye peremennye
	mov  ax, cs
	mov  [rc], ax
	mov  ax, ds
	mov  [rd], ax
	mov  ax, es
	mov  [re], ax
	mov  ax, ss
	mov  [rs], ax
	mov  [ri0], offset Proc1 //adresa nachala procedur
	mov  [ri1], offset Proc2
	pushf
	pop  ax
	mov  [f], ax
		}
		for(i=0;i<2;i++) //zapisyvaem znacheniya segmentnyh registrov,
		{                //flagov
	Stats[i].rcs = rc;  //i adresa nacha procedur
	Stats[i].rds = rd;  //v sootvetstvuyushye konteksty
	Stats[i].res = re;
	Stats[i].rss = rs;
	Stats[i].rflags = f;
		}
		Stats[0].rip = ri0;
		Stats[1].rip = ri1;
		current_proc = 0; //tekushaya procedura - pervaya
		stats_offset = (unsigned)&Stats; //adres nachala massiva
		oldHandler = getvect(0x9); //perekluchaemsya po najatiyu klavishy
		setvect(0x9,IntHandler);
		Proc1();
		setvect(0x9,oldHandler);

		return 0;
}

void Proc1(void)
{
		while(1){
	 /*	asm{
	mov bx,0xb800
	mov es,bx
	mov bx,0
	mov si,bx
	mov bx,0x31
	mov [es:si],bx
	mov bx,1
	mov si,bx
	mov bx,0x04
	mov [es:si],bx
	}  */
	disable();
	printf("%d\n",1);
	delay(10);
	enable(); }
}

void Proc2(void)
{
		while(1) {
/*		 asm{
	mov bx,0xb800
	mov es,bx
	mov bx,0
	mov si,bx
	mov bx,0x32
	mov [es:si],bx
	mov bx,1
	mov si,bx
	mov bx,0x02
	mov [es:si],bx

	} */
	disable();
	printf("%d\n",2);
	delay(10);
	enable();}
}

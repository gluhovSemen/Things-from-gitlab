 //      "Обмен IBM PC с клавиатурой"
//             Labv10

#include <iostream.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <bios.h>
#define Port8042 0x60

long far * pTime=(long far*)0x46C;   // Указатель на счетчик тиков

// Определим указатели начала и конца буфера

int far * pHeadPtr=(int far  *)0x41A;   // Указатель на указатель головы буф.кл.
int far * pTailPtr=(int far  *)0x41C;   // Указатель на указатель хвоста буф.кл.
unsigned char far * pBuf;
union CODE {
	struct
	{
	  unsigned char ascii;
	  unsigned char scan;
	} c;
        unsigned int i;
};

void main()
{
// 3адание N1.

	clrscr();
	CODE code;
	while (getch() != 32) {
	asm mov ah , 0x10
	asm int 0x16
	asm mov code.i , ax
        printf (  "scan : %x\nascii code : %x\n\n"  , code.c.scan , code.c.ascii);
	/*
		int a = 0;
		asm in al, 0x60
		asm mov cl, al
m1:
		asm in al, 0x60
		asm cmp al, cl
		asm je m1

		a=_AL;
		asm push ds
		asm push si
		asm push di
		asm mov ax, 0x40
		asm mov ds, ax
		asm mov si, 0x17
		asm mov al, [si]
		asm mov di, 0x18
		asm mov ah, [di]

		asm pop di
		asm pop si
		asm pop ds

		int b = _AL;
		int c = _AH;
		cout << hex << b << " " <<  c << " " << a << "\n";
	*/
	}
}
// Задание
// 1 Разберите представленную программу
//  Определите отличие ASCII кодов: основных и служебных клавиш
// 2 Напишите мини программу циклического чтения скан кодов из порта 60
//  Определите отличие скан кодов: нажатия и отпускания клавиши


#include <stdio.h>
#include <conio.h>

int main (void){
  clrscr();

  //Коды команд
  asm{ inc ax
       not ax
       jb m1
       sar ax, 1
     };

  m1:

  //Методы записи массива A в массив B
  //1. JNZ
  int A[5] = {1,2,3,4,5};
  int B[5] = {0,0,0,0,0};

  for (int i = 0; i<5; i++){
    printf("%i   %i\n",A[i],B[i]);
  };

  asm{
	lea bx, A
	lea si, B
	mov cx, 5
  };

  M2:
  asm{
	mov ax, [bx]
	mov [si], ax
	add bx, 2
	add si, 2
	dec cx
	jnz M2
  };

  printf("\n");

  for (int j = 0; j<5; j++){
    printf("%i   %i\n",A[j],B[j]);
  };

  //2. LOOP
  int C[5] = {5,4,3,2,1};

  asm{
	lea bx, C
	lea si, B
	mov cx, 5
  };

  M3:
  asm{
	mov ax, [bx]
	mov [si], ax
	add bx, 2
	add si, 2
	loop M3
  };

  printf("\n");

  for (j = 0; j<5; j++){
    printf("%i   %i\n",C[j],B[j]);
  };

  //3. REP MOVSW
  int D[5] = {1,2,4,2,1};

  asm{
	lea si, D
	lea di, B
	mov cx, 5
	rep movsw
  };

  printf("\n");

  for (j = 0; j<5; j++){
    printf("%i   %i\n",D[j],B[j]);
  };

  //4. MOVSB
  int E[5] = {3,2,1,2,3};
  int far * pE = &E[0];
  int far * pB = &B[0];

  asm{
	lds si, pE
	les di, pB
	push si
	push di
	mov cx, 10
	rep movsb
	pop si
	pop di
  };

  printf("\n");

  for (j = 0; j<5; j++){
    printf("%i   %i\n",E[j],B[j]);
  };

  int far * p1 = (int *) 0xb8000000;
  int far * p2 = (int *) 0xb8100000;

  asm {
	push es
	push ds
	lds si, p1;
	les di, p2;
	mov cx, 10
	rep movsb
	pop es
	pop ds
  };

  return 0;
}

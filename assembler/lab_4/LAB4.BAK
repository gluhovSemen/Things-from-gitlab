#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <conio.h>

int iB=0x1234;
int A[90]={0,1,2,3,4,5,6,7,8,9};

void main(void)
{
//  int iA=0x5678;
  clrscr();
  printf ("\n Array filling \n");

  for (int i = 0 ; i < 90 ; i++) {
    A[i] = i;
    printf (" %d ", A[i]);
  }

  getch();

  asm   mov si, 20
  asm   lea bx, A
e2:
  asm {
	mov cx, 10
	mov ax, 0
      };
e1:     asm mov [bx + si],ax
	asm add bx, 2
	asm loop e1

	asm add si, 20
	asm mov ax, 100
	asm cmp ax, si
	asm ja e2

  for (i = 0; i < 9; i++) {
    printf (" \n   ");
    for (int j=0; j < 10; j++) {
      printf (" %d ", *(A + i * 10 + j));
    }
  }
  printf("\n");
  getch();

  asm   lea bx, A
  asm   lea di, A
  asm   add bx, 180
e4:
  asm {
	mov cx, 10
	mov ax, 2
	  };

	asm rep stosw

	asm add di, 20
	asm cmp bx, di
	asm ja e4

  for (i = 0; i < 9; i++) {
	printf (" \n   ");
	for (int j = 0; j < 10; j++) {
	  printf (" %d ", *(A + i * 10 + j));
	}
  }

  getch();
}

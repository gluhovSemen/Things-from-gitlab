#include <stdio.h>
#include <time.h>
#include <conio.h>

void main(void)
{
  clrscr();

  const long int cycle = 100000000;

  clock_t start = clock();

  for (long int i = 0; i < cycle; i++) {
	asm {
		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx

		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx

		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx

		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx
		  add ax, bx
	};
  }

  clock_t stop = clock();

  printf( " add ax, bx %f \n", (stop - start)/CLK_TCK);

  start = clock();

  for (i = 0; i < cycle; i++) {
	asm {
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]

		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]

		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]

		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
		  add ax, [bx]
	};
  }

  stop = clock();

  printf( " add ax, [bx] %f \n", (stop - start)/CLK_TCK);

  start = clock();

  for (i = 0; i < cycle; i++) {
	asm {
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax

		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax

		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax

		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
		  add [bx], ax
	};
  }

  stop = clock();

  printf( " add [bx], ax %f \n", (stop - start)/CLK_TCK);

	start = clock();

  for (i = 0; i < cycle; i++) {
	asm {
		  add si, di
		  add si, di
		  add si, di
		  add si, di
		  add si, di

		  add si, di
		  add si, di
		  add si, di
		  add si, di
		  add si, di

		  add si, di
		  add si, di
		  add si, di
		  add si, di
		  add si, di

		  add si, di
		  add si, di
		  add si, di
		  add si, di
		  add si, di
	};
  }

  stop = clock();

  printf( " add si, di %f \n", (stop - start)/CLK_TCK);

  getch();
};
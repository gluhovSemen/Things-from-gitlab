/*                       LAB6
		Лабораторная работа по теме
		  "Программные прерывания"


При вызове функции - прерывания из СИ, используется INT.
В связи с этим стек заполняется несколько иначе.
В стеке сохраняются значения IP, СS (сегмент кода),от куда вызывается
прерывание, и флаги.
Выход из INT осуществляется с помощью IRet,которая вынимает из стека
все старые регистров CS, IP и флагов.
Так же при вызове прерывания,флажок прерывания i и t
устанавливается в 0, что запрещает вызов любых других прерываний,
а также запрещает трассировку.
*/
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include <conio.h>

void interrupt (*old)(...);     // здесь будем сохранять старый вектор
void interrupt cmp_int(...)     // а это наш обработчик
{
cout<<"Прерывание  ";
getch();

}

long b;
long res;

void interrupt rol3(...)
{
		asm {
			 lea  SI, b
			 lea  DI, res
			 mov	AX, [SI+2]
			 mov 	BX, [SI]
			 shl  AX, 1
			 rcl  BX, 1
			 adc  AX, 0
			 mov  [DI], BX
			 mov  [DI+2], AX

			 mov  AX, 2;
			 add  [BP+18], AX
			 }

}

void main(void)
{
	clrscr();
	b = 2;
	printf("rol %d \n", b);
	old=getvect(0xf0);
	disable();
	setvect(0xf0,rol3);

	enable();
	geninterrupt(0xf0);
	setvect(0xf0,old);

	printf("result:  %d \n", res);

	b = 8;
	printf("rol %d \n", b);
	old=getvect(0x0);
	disable();
	setvect(0x0,rol3);
	enable();
	b = b / 0;

	printf("result:  %d \n", res);

	getch();
	return;
// Задания
// 1 Напишите программу обработки прерывания
// 2 Вызовите прерывание путем организации особого случая
// 3 Покажите использование команды int3, определите ее код с испол. TD
	}

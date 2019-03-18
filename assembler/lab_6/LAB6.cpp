
//                 Работа N LAB5
//              Шаблон программы
// Тема         - ПОДПРПОГРАММЫ

#include <stdio.h>
#include<conio.h>
#include<iostream.h>

/*
При вызове функции в Си, она интерпретируется как команда Call
в Assembler. При этом передаваемые в функцию параметры, заносятся в
СТЕК по принципу справа налево. Затем заносится IP следующей команды,
идущей за Call. (внутрисегментный вызов процедуры)
Выход из функции осуществляется с помощью команды RET.
*/

//Функция, выполняющая сложение, параметры перед через стек
//void addition()
//{

 //    asm{
	 //    mov     AX,[BX]         //AX - младшие pазpяды пеpвого слагаемого
		//   mov     DX,[SI]        //DX - младшие pазpяды второго слагаемого
		 //  mov     SI,[BP+14]       //SI - сумма младших pазpядов
	//     add     AX,DX            //сложение младших pазpядов
	 //    mov     [SI],AX          //pезультат косвенно в SI
		//   mov     ss:[di],ax
	//     mov     AX,[BX+2]        //AX - стаpшие pазpяды пеpвого слагаемого
	 //    mov     DX,[SI+2]       //DX - младшие pазpяды второго слагаемого
		//   adc     ax,dx 		  //сложение стаpших pазpядов
		//   mov     ss:[dI+2],AX        //pезультат в SI
	 // }
//    sum=sl_2;
//}

long b;
long res2;

void rol1(long a, long &res)
{
		a = a;
		asm {
			 mov	AX, [BP+6]
			 mov 	BX, [BP+8]
			 shl  AX, 1
			 rcl  BX, 1
			 adc  AX, 0
			 mov  SI, [BP+10]
			 mov  ss:[SI], AX
			 mov  ss:[SI+2], BX
			 }
		res = res;

}

void rol2()
{
		asm {
			 mov	AX, [SI+2]
			 mov 	BX, [SI]
			 shl  AX, 1
			 rcl  BX, 1
			 adc  AX, 0
			 mov  [DI], BX
			 mov  [DI+2], AX
			 }

}


void rol3()
{
		asm {
			 lea  SI, b
			 lea  DI, res2
			 mov	AX, [SI+2]
			 mov 	BX, [SI]
			 shl  AX, 1
			 rcl  BX, 1
			 adc  AX, 0
			 mov  [DI], BX
			 mov  [DI+2], AX
			 }

}


void main ( void )
{
clrscr();

long a;
long res=0;

cout<<"\n Enter number:  ";
cin>>a;

rol1(a, res);

cout<<"rol1 a "<<res<<"\n";

asm{
	lea SI, a
	lea DI, res
};

rol2();

cout<<"rol2 a "<<res<<"\n";

b = a;
rol3();
cout<<"rol3 a "<<res2;


getch();
}

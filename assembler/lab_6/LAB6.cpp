
//                 ����� N LAB5
//              ������ �ணࠬ��
// ����         - �������������

#include <stdio.h>
#include<conio.h>
#include<iostream.h>

/*
�� �맮�� �㭪樨 � ��, ��� ����������� ��� ������� Call
� Assembler. �� �⮬ ��।������ � �㭪�� ��ࠬ����, ��������� �
���� �� �ਭ樯� �ࠢ� ������. ��⥬ �������� IP ᫥���饩 �������,
���饩 �� Call. (�����ᥣ����� �맮� ��楤���)
��室 �� �㭪樨 �����⢫���� � ������� ������� RET.
*/

//�㭪��, �믮������ ᫮�����, ��ࠬ���� ��। �१ �⥪
//void addition()
//{

 //    asm{
	 //    mov     AX,[BX]         //AX - ����訥 p��p�� ��p���� ᫠�������
		//   mov     DX,[SI]        //DX - ����訥 p��p�� ��ண� ᫠�������
		 //  mov     SI,[BP+14]       //SI - �㬬� ������ p��p冷�
	//     add     AX,DX            //᫮����� ������ p��p冷�
	 //    mov     [SI],AX          //p������ ��ᢥ��� � SI
		//   mov     ss:[di],ax
	//     mov     AX,[BX+2]        //AX - ��p訥 p��p�� ��p���� ᫠�������
	 //    mov     DX,[SI+2]       //DX - ����訥 p��p�� ��ண� ᫠�������
		//   adc     ax,dx 		  //᫮����� ��p�� p��p冷�
		//   mov     ss:[dI+2],AX        //p������ � SI
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

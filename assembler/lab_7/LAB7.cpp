/*                       LAB6
		������ୠ� ࠡ�� �� ⥬�
		  "�ணࠬ��� ���뢠���"


�� �맮�� �㭪樨 - ���뢠��� �� ��, �ᯮ������ INT.
� �裡 � �⨬ �⥪ ���������� ��᪮�쪮 ����.
� �⥪� ��࠭����� ���祭�� IP, �S (ᥣ���� ����),�� �㤠 ��뢠����
���뢠���, � 䫠��.
��室 �� INT �����⢫���� � ������� IRet,����� �뭨���� �� �⥪�
�� ���� ॣ���஢ CS, IP � 䫠���.
��� �� �� �맮�� ���뢠���,䫠��� ���뢠��� i � t
��⠭���������� � 0, �� ����頥� �맮� ���� ��㣨� ���뢠���,
� ⠪�� ����頥� ����஢��.
*/
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include <conio.h>

void interrupt (*old)(...);     // ����� �㤥� ��࠭��� ���� �����
void interrupt cmp_int(...)     // � �� ��� ��ࠡ��稪
{
cout<<"���뢠���  ";
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
// �������
// 1 ������ �ணࠬ�� ��ࠡ�⪨ ���뢠���
// 2 �맮��� ���뢠��� ��⥬ �࣠����樨 �ᮡ��� ����
// 3 ������� �ᯮ�짮����� ������� int3, ��।���� �� ��� � �ᯮ�. TD
	}

.model large
.data
Str1 db 'exit from debug ''$' 

code segment
assume cs:code, ds:code, es:code, ss:code 
org 100h
start:

;������� �� ������ 
jmp beg

print_symbol:

;����������� ������ 
push ax

push dx

mov ah, 02h 
mov dl, dh 
cmp dl, 0 
je t2

int 21h 
t2:

pop dx 
int 21h 
pop ax 
ret

print_number:

;����������� �����, base = 10 
push ax

push bx 
push cx 
push dx 
mov ax, dx 
mov bx, 10

mov cx, 0 
getdigits:

mov dx, 0 
div bx 
inc cx

add dx, 30h 
push dx

cmp ax, 0

jnz getdigits 
mov ah, 02h 
printdigits:

pop dx 
int 21h

loop printdigits 
pop dx

pop cx 
pop bx 
pop ax 
ret

debug:
  
;��������� ��������, ��������� ���������� 
cli

push bp 
mov bp, sp 
push ax 
push bx 
push cx 
push dx 
push si

;������� ip � ax 
mov dx, '['

call print_symbol 
mov dx, [bp+2] 
call print_number 
mov dx, ','

call print_symbol 
mov dx, [bp-2] 
call print_number 
mov dx, ']'

call print_symbol 
mov dx, etr

call print_symbol

;������� ������� ������� 
xor ax , ax
int 16h 
 
         


;������������ ��������, ��������� ����������
cmp al, 20h
   je ifnot
  
   jmp endif
ifnot:
mov ax,@data
mov ds,ax
lea dx, Str1
mov ah, 9h                      
int  21h 
mov AH , 4ch
int 21h                                    ;;;;;;
    jmp met 
endif: 
pop si 
pop dx 
pop cx 
pop bx 
pop ax 
pop bp 
sti 
iret

;������������ ��������� 
thread:

mov ax, 1

mov cx, 10 
t1:
add ax, ax 
loop t1 
ret

beg:           

;��������� ������ ���������� 
mov ax, 3501h

int 21h

mov int1, bx 
mov int1+2, es

;���������� ����� ���������� 
push cs

pop ds

mov dx, offset debug 
mov ax, 2501h

int 21h

;��������� �������� ��� �������� 
pushf

push offset exit

;��������� TF ���� 
met:
pushf
pop ax

or ax, 100h 
push ax 
push cs


push offset thread 

iret

exit: 
popf

;���������� ������ ����������

lea dx, int1 
mov ax, 2501h 
int 21h
                                
;����� ����� ������� ������� 
mov ah , 01h
int 21h
int 20h

int1 dw 0h, 0h 
etr dw 0Ah, 0Dh

code ends 
end start
    DOSSEG
   .MODEL TINY
   .STACK 100h
   .DATA
Message  DB 13,10,'Hi ������! ',13,10,'$'
   .CODE
   mov    ax,@Data
   mov    ds,ax                  ; ���������� ������� DS �����
                                     ; �������, ����� �� ��������
                                     ; �� ������� ������
   mov    ah,9                    ; ������� DOS ������ ������
   mov    dx,OFFSET Message       ; ������ �� ��������� "������!"
   int    21h                     ; ������� "������!" �� �����
   mov    ah,4ch              ; ������� DOS ����������
                                     ; ���������
   int    21h                     ; ��������� ���������
   END
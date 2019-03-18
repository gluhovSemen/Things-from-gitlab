;DOS, TASM, COM-файл
;tasm.exe /m filename.asm
;tlink.exe /t /x filename.obj
;
.model tiny
.386
.code
ORG 8Dh
Ind dw  ?   ;число файлов в папке
Klast   dw  ?   ;номер кластера начала внешней папки
ORG 95h
Attrib  db  ?   ;атрибут файла
Tim dw  ?   ;время
Dat dw  ?   ;дата
Siz dd  ?   ;размер
File    db  ?   ;имя
ORG 100h
START:
;дать текущий диск. После в AL текущий логический диск (0=A, 1=B, 2=C и т.д.)
        mov ah,19h
        int 21h
        lea bx,Tabl
        xlat
        mov [Disk],al
        lea dx,Strin    ;на строку с логическим диском
    call vivod  ;вывод ее на экран
;дать текущий путь. После в DS:SI текущая папка с завершающим 0
        mov ah,47h
        lea si,Path     ;буфер результата
        xor dl,dl       ;0 - текущий диск
        int 21h
 
        lea si,Disk     ;выводим текущий путь
        call vivodB     ;посимвольно
    lea dx,Per      ;перевод строки
    call vivod
    lea dx,Per      ;еще один перевод строки
 
    call vivod
    lea dx,Shapka
    call vivod
    lea dx,Per
    call vivod
    cmp byte ptr [si-1],'\' ;у корня уже есть этот символ
    jz short no_slash   ;и тогда для полного пути он не нужен
    mov byte ptr [si],'\'   ;а если не корень то подставляем его
    inc si
no_slash:
    mov dword ptr [si],002a2e2ah ;искать по маске *.* в конце 0
    lea dx,Disk ;маска для поиска
    mov cl,0FFh ;все атрибуты
    mov ah,4Eh  ;найти первый совпадающий файл
    int 21h
    lea si,File ;исходная строка в DAT
    lea dx,Inf  ;строка результат
    call inf_   ;заполнение,вывод на экран и очистка строки
m_01:
    mov ah,4Fh  ;найти следующий файл
    int 21h
    jc short exit   ;установлен ли флаг,и если да то выход
    lea si,File ;иначе вывод на экран
    call inf_
    jmp short m_01  ;и продолжить поиск следующего файла
    
exit:
    mov ax,[Ind_Files]  ;число файлов в папке
    lea si,Ind_S        ;строка для результата
    call _16_assci      ;преобразовать
    mov eax,[Summa_Files]   ;объем всех файлов
    lea si,Summa        ;строка для результата
    call _16_assci      ;преобразовать
    lea dx,Summa_S      ;и все ото вывести на экран
    call vivod
;
        ret         ;выход из проги
;--------- Процедура вывода на экран строки до символа '$' ---------
vivod        proc        near
        mov ah,9
        int 21h
        ret
vivod        endp
;--------- Процедура вывода на экран по символу до (0) ------
vivodB        proc        near
start_vivodB:
        mov dl,[si]     ;в DL символ
        cmp dl,0
        jz short exit_vivodB
        mov ah,2        ;функция вывода на экран по 1 символу
        int 21h
        inc si          ;на следующий символ для вывода
        jmp short start_vivodB
exit_vivodB:
        ret
vivodB        endp
;------------------
inf_    proc    near
    mov di,dx       ;DX всегда на строке результата
push di
    call vivod_S
;подготовка строки для остальной инфы о файле
    test [Attrib],00010000b ;папка?
    jnz short papka_m
    test [Attrib],00001000b ;метка?
    jnz short metka_m
    inc word ptr [Ind_files];это не папка и не метка а файл. Значит увели
                ;чить индекс количества файлов 
    mov eax,[Summa_Files]
    add eax,[Siz]
    mov [Summa_Files],eax
    test [Attrib],00100000b ;архивный?
    jnz short arh_m
    jmp short no_arh_m
arh_m:
    lea si,A_S      ;исходная строка
    lea di,Papka+1      ;строка результат
    call vivod_S        ;скопировать исходную в результат
no_arh_m:
    test [Attrib],00000001b ;чтения?
    jnz short read_m
    jmp short no_read_m
read_m:
    lea si,R_S
    lea di,Papka+2
    call vivod_S
no_read_m:
    test [Attrib],00000010b ;скрытый?
    jnz short hint_m
    jmp short no_hint_m
hint_m:
    lea si,H_S
    lea di,Papka+3
    call vivod_S
no_hint_m:
    test [Attrib],00000100b ;системный?
    jnz short sys_m
    jmp short exx
sys_m:
    lea si,S_S
    lea di,Papka+4
    call vivod_S
    jmp short exx
papka_m:
    lea si,Papka_S
    lea di,Papka
    call vivod_S
    jmp short papk
metka_m:
    lea si,Metka
    lea di,Papka
    call vivod_S
    jmp short papk
exx:
    mov eax,[Siz]       ;размер файла
    lea si,@Size        ;строка для результата
    call _16_assci      ;преобразовать
papk:
    mov ax,[Dat]
    and ax,0000000000011111b;день 0-4 биты
    lea si,Day
    mov word ptr [si+1],'0.'
    call _16_assci
    mov ax,[Dat]
    and ax,0000000111100000b;месяц 5-8 биты
    shr ax,5
    lea si,Mans
    mov byte ptr [si+1],'.'
    call _16_assci
    mov ax,[Dat]
    and ax,1111111000000000b;год 9-15 биты
    shr ax,9
    add ax,80       ;с 1980 года
    lea si,Year
    call _16_assci
    mov byte ptr [Mans+1],'.'
    mov ax,[Tim]
    and ax,1111100000000000b;час 11-15 биты
    shr ax,11
    lea si,Time_Ch
    mov word ptr [si+1],'0:'
    call _16_assci
    mov ax,[Tim]
    and ax,0000011111100000b;минуты 5-10 биты
    shr ax,5
    lea si,Time_Min
    call _16_assci
    mov ax,[Klast]
    lea si,Klast_S
    call _16_assci
;
    call vivod      ;вывод всей строки
pop di
;очистка строки
    mov cx,53
    mov al,' '
loop_inf_:
    mov [di],al
    inc di
loop loop_inf_
;   mov byte ptr [di],'@'
    ret
inf_    endp
;-- Пересылка строки из SI в DI до символа (0) ----------------
vivod_S proc    near
start_vivod_S:
    mov al,[si]
    cmp al,0
    jz short exit_vivod_S
    mov [di],al
    inc si
    inc di
    jmp short start_vivod_S
exit_vivod_S:
    ret
vivod_s endp
;------------------
;преобразование 16-ричных чисел в 10-ричные
;Разрушаемый EAX - преобразуемое число
;Разрушаемый SI - указатель на конец строки результата
_16_assci   proc    near
    xor bl,bl
push dx
    mov ecx,10
c10_m0:
    cmp eax,10
    jb short c10_m1
        xor edx,edx
        div ecx
        or dl,30h
        mov byte ptr [si],dl
        dec si
    inc bl
    cmp bl,3        ;между 3 символами пробел 000 000 000
    jnz short no_probel_c10
    mov byte ptr [si],' '
    dec si
    xor bl,bl
no_probel_c10:
        jmp short c10_m0
c10_m1:
        or al,30h
        mov byte ptr [si],al
pop dx
    xor eax,eax
        ret
_16_assci   endp
;--------------------------------------
Inf db  '               '
Papka   db  '                    '
@Size:
    db  '    '
Day:
    db  ' . '
Mans:
    db  ' . '
Year:
    db  ' '
    db  '   '
Time_Ch:
    db  ' : '
Time_Min:
    db  ' ',10,13,'$'
Summa_S db  10,13,'‚ Ї*ЇЄҐ '
    db  '    '
Ind_S:
    db  '  д*©«(®ў). ЋЎкҐ¬ '
    db  '           '
Summa:
    db  '  Ў*©в.  Љ«*бвҐа      '
Klast_S:
    db  ' ',10,13,'$'
Ind_Files   dw  0
Summa_Files dd  0
Papka_S db  '<ЏЂЏЉЂ>',0
Metka   db  '<ЊҐвЄ* в®¬*>',0
A_S db  'A',0
S_S db  'S',0
H_S db  'H',0
R_S db  'R',0
Per db  10,13,'$'
Tabl    db  'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
Shapka  db  '€¬п д*©«*      ЂваЁЎгвл       ђ*§¬Ґа      „*в*  ‚аҐ¬п',10,13
    db  '-----------------------------------------------------$'
Strin   db  10,13,'‘®¤Ґа¦Ё¬®Ґ Ї*ЇЄЁ $'
Disk    db  0,':\'
Path    db  ?
;-----------------------------------------------------
end start

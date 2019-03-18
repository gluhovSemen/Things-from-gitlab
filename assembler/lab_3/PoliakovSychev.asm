    DOSSEG
   .MODEL TINY
   .STACK 100h
   .DATA
Message  DB 13,10,'Hi Привет! ',13,10,'$'
   .CODE
   mov    ax,@Data
   mov    ds,ax                  ; установить регистр DS таким
                                     ; образом, чтобы он указывал
                                     ; на сегмент данных
   mov    ah,9                    ; функция DOS вывода строки
   mov    dx,OFFSET Message       ; ссылка на сообщение "Привет!"
   int    21h                     ; вывести "Привет!" на экран
   mov    ah,4ch              ; функция DOS завершения
                                     ; программы
   int    21h                     ; завершить программу
   END
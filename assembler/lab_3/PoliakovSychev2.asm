    DOSSEG
   .MODEL TINY
   .STACK 100h
   .DATA
   A DB 0,1,2,3,4,5,6,7,8,9
   B DB 10 DUP  (0)
   .CODE
   mov    ax,@Data
   mov    ds,ax                  
   mov    es,ax                       
                                     
   cld
   lea si, A
   lea di, B
   mov cx, 10
   rep movsw
   
   mov cx, 10
   lea bx, B
   
m1:
   mov    dx, [bx]
   add    dl,30h
   mov    ah,2                    
   
   int    21h 
   inc bx
   loop m1
                       
   mov    ah,4ch              ; функция DOS завершения
                                     ; программы
   int    21h                     ; завершить программу
   END
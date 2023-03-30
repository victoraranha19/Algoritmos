.686
.model flat, stdcall
option casemap:none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    n1 DD 10                         ;numero fatorial
    r1 DD 0                          ;resultado

.code
start:
    mov edx, 0
    mov eax, 1                       ;inicializa eax = 1 (para ajudar na multiplicacao)

    push n1                          ;passa o parametro n1
    call fatorial                    ;chama a funcao fatorial

    mov r1, eax                      ;armazena o resultado de eax em r1
    
    printf("Fatorial: %d \n", n1)
    printf("Resultado = %d \n", r1)

    invoke ExitProcess,0


    fatorial:                        ;funcao recursiva fatorial (eax = n1 * n1-1 * ... * 1)
        push ebp
        mov ebp, esp
        
        mov ecx, [ebp + 8]           ;armazena o parametro em ecx
        
        cmp ecx, 1                   ;caso base
        jle retorno1                 ;se ecx <= 1 retorna eax

        mul ecx                      ;caso indutivo
        dec ecx                      ;se ecx > 1
        push ecx                     ;eax *= ecx
        call fatorial                ;fatorial(ecx-1)
        
        retorno1:                    ;retorna eax
        pop ebp
        ret 4
end start
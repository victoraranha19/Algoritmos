ifndef X64
.686
.model flat, stdcall
endif
option casemap:none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    n1 DQ 20                         ;numero fatorial
    r1 DQ 0                          ;resultado

.code
start:
    mov rdx, 0
    mov rax, 1                       ;inicializa rax = 1 (para ajudar na multiplicacao)

    push n1                          ;passa o parametro n1
    call fatorial                    ;chama a funcao fatorial

    mov r1, rax                      ;armazena o resultado de rax em r1
    
    printf("Fatorial: %lld \n", n1)
    printf("Resultado = %lld \n", r1)

    invoke ExitProcess,0


    fatorial:                        ;funcao recursiva fatorial (rax = n1 * n1-1 * ... * 1)
        push rbp
        mov rbp, rsp
        
        mov rcx, [rbp + 8]           ;armazena o parametro em rcx
        
        cmp rcx, 1                   ;caso base
        jle retorno1                 ;se rcx <= 1 retorna rax

        mul rcx                      ;caso indutivo
        dec rcx                      ;se rcx > 1
        push rcx                     ;rax *= rcx
        call fatorial                ;fatorial(rcx-1)
        
        retorno1:                    ;retorna rax
        pop rbp
        ret 8
end start

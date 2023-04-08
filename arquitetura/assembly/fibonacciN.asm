.686
.model flat, stdcall
option casemap:none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    n1 DD 10                         ;numero fibonacci
    r1 DD 0                          ;resultado

.code
start:
    mov edx, 0                       ;(primeiros fibonacci)
    mov eax, 1                       ;inicializa edx,eax = 0,1

    push n1                          ;passa o parametro n1
    call fibonacci                   ;chama a funcao fibonacci

    mov r1, eax                      ;armazena o resultado de eax em r1
    
    printf("Fibonacci: %d \n", n1)
    printf("Resultado = %d \n", r1)

    invoke ExitProcess,0


    fibonacci:                       ;funcao recursiva fibonacci (n1,0,1)
        push ebp                     ;(prologo)
        mov ebp, esp                 ;
        
        mov ecx, dword ptr [ebp][8]  ;armazena o parametro em ecx

        cmp ecx, 1                   ;caso base 1
        jle retorno0                 ;se ecx <= 1 retorna eax=0

        cmp ecx, 2                   ;caso base 2
        je retorno1                  ;se ecx == 2 retorna eax

        mov ebx, eax                 ;caso indutivo
        add eax, edx                 ;(novo_eax = eax+edx)
        mov edx, ebx                 ;(novo_edx = eax)
        dec ecx                      ;(ebx para auxiliar a troca)
        push ecx                     ;
        call fibonacci               ;fibonacci(ecx-1,eax,eax+edx)
        jmp retorno1                 ;retorna eax
        
        retorno0:                    ;retornar eax=0
        mov eax, 0                   ;
        
        retorno1:                    ;retornar eax
        pop ebp                      ;
        ret 4                        ;
end start
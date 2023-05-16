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
    p1 DD 0
    p2 DD 1
    r1 DD 0                          ;resultado

.code
start:
    printf("Fibonacci: %d \n", n1)

    push n1                          ;
    push p1                          ;
    push p2                          ;
    call fibonacci                   ;chama a funcao fibonacci(n1,p1,p2)

    mov r1, eax                      ;armazena o resultado de eax em r1
    printf("%d \n", r1)              ;printa o ultimo da sequencia

    invoke ExitProcess,0


    fibonacci:                       ;funcao recursiva fibonacci (n1,0,1)
        push ebp                     ;(prologo)
        mov ebp, esp                 ;
        
        mov ecx, dword ptr [ebp][16] ;armazena o parametro n1 em ecx
        mov edx, dword ptr [ebp][12] ;armazena o parametro p1 em edx
        mov eax, dword ptr [ebp][8]  ;armazena o parametro p2 em eax


        pop ebp                      ;
        ret 12                       ;
end start
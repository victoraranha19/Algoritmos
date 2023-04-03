.686
.model flat, stdcall
option casemap :none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    fator DD 6
    
.code
start: 

    sub eax,eax
    push fator
    call fatorial
    printf("Resultado fatorial: %d \n", eax)
    jmp fim

fatorial:
    push ebp ;prólogo
    mov ebp,esp
    
    ;implementação
    mov ecx, dword ptr [ebp][8] ;teste do parâmetro igual a 1
    cmp ecx,1
    je epilogo ;Se for 1. 

    dec ecx
    push ecx
    call fatorial
    
epilogo:
    mov eax,dword ptr [ebp][8]
    mul ecx ;guarda em eax a multiplicacao
    mov ecx,eax
    mov esp,ebp
    pop ebp
    ret 4
    
fim:
    invoke ExitProcess,0
end start
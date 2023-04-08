.686
.model flat, stdcall
option casemap:none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    X DD 2                   ;X quantidade de notas
    notas DD 10,6            ;vetor notas
    media DD 0

.code
start:
    ;media = (notas[0] + notas[1] + ... + notas[X-1]) / X

    mov eax, 0
    mov ebx, offset notas
    mov ecx, 0
    mov edx, 0

    loop1:                   ;soma dos X inteiros
    add eax, [ebx][edx]      ;
    add edx, 4               ;edx incrementa 4 (DD)
    inc ecx                  ;ecx++
    cmp ecx, X               ;
    jne loop1                ;loop enquanto ecx for diferente de X

    mov edx, 0
    div X
    mov media, eax

    printf("Valor aproximado da media: %d \n", media)
    invoke ExitProcess,0

end start
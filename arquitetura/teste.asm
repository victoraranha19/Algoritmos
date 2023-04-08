.686
.model flat, stdcall
option casemap :none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    notas REAL4 8.8,4 DUP(5.5),7.3,3 DUP(10.0),9.5, -1
    media REAL4 0

.code
start: 
    mov ecx, 0
    mov edx, 0
    mov eax, 0

    loop1:
    fadd eax, notas[ecx]
    inc edx
    add ecx, 4
    mov ebx, notas[ecx]
    cmp notas[ecx], -1
    jne loop1

    fdiv ecx
    mov media, eax
    printf("Media: %f \n", media)
   
    invoke ExitProcess,0
end start
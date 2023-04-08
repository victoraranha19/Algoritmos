.686
.model flat, stdcall
option casemap :none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    nNotas DD 3
    vNotas DB 2,5,7

.code
start: 
    sub ecx,ecx
    sub edx,edx
    sub eax,eax

repeticao:
    add al, vNotas[ecx]
    inc ecx
    cmp ecx,nNotas
    jl repeticao


    div nNotas
    printf("Media: %d \n", eax)
   
    invoke ExitProcess,0
end start
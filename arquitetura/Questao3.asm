.686
.model flat, stdcall
option casemap :none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    n1 DD 2500000000
    ;n1 DD 8
    n2 DD 2
    
.code
start: 
    mov eax,n1
    mul n2
    jc fim64
    sub edx,edx

fim64:
    printf("Multiplicacao: %I64d \n", edx::eax)
   
    invoke ExitProcess,0
end start
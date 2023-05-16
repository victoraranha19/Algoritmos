.686
.model flat, stdcall
option casemap :none

include \masm32\include\kernel32.inc
include \masm32\include\msvcrt.inc
include \masm32\macros\macros.asm

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\msvcrt.lib

.data
    notas REAL4 9.5, 1.1, 7.3, 5.5, -1.0     ;flag de parada do vetor -1
    total REAL4 0.0
    media REAL4 0.0

.code
start: 
    sub ecx, ecx                             ;registrador para contar notas
    sub edx, edx                             ;registrador para pular
    sub eax, eax

    loop1:                                   ;faz loop1:
    fadd total, notas[edx]                   ;adiciona a soma em media
    inc ecx                                  ;quantidade de notas antes de -1
    add edx, 4                               ;pula pro proximo elemento do vetor (4 bytes)
    cmp notas[edx], -1                       ;
    jne loop1                                ;enquanto elemento for diferente de -1, faz loop1:

    mov eax, total                           ;calcular a media:
    fdiv ecx                                 ;divide o total pela quantidade (ecx)
    mov media, eax                           ;armazena em media
    printf("Media: %f \n", media)
   
    invoke ExitProcess,0
end start
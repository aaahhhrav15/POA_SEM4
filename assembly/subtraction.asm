org 100h
MOV AX,[1000h]
MOV BX,[1002h]
MOV CL,00h
SUB AX,BX
MOV [1004h],AX
JNC jump
INC CL
jump:
MOV [1006h],CL
HLT
ret
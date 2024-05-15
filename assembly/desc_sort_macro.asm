sort macro
    MOV CH,04H
    
    L1:
    MOV CL,04H
    LEA SI,STRING 
    
    L2:
    MOV AL,[SI]
    MOV BL,[SI+1]
    CMP BL,AL
    JC jump
    MOV DL,[SI+1]
    XCHG DL,[SI]
    MOV [SI+1],DL
    
    jump:
    INC SI
    DEC CL
    JNZ L2
    DEC CH
    JNZ L1
endm

DATA SEGMENT 
    STRING DB 99h,12h,36h,45h,54h
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
    MOV AX,DATA
    MOV DS,AX
    sort
CODE ENDS
END START
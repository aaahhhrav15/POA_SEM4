DATA SEGMENT
    ARR DB 09h,01h,02h,05h,06h
    LEN DW $-ARR
    MIN DB ?
    MAX DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
    MOV AX,DATA
    MOV DS,AX
    LEA SI,ARR
    MOV AL,ARR[SI]
    MOV MIN,AL
    MOV MAX,AL 
    MOV CX,LEN  
    
    REPEAT:
    MOV AL,ARR[SI]
    CMP MIN,AL
    JL large 
    MOV MIN,AL
    
    large:
    CMP MAX,AL
    JG done 
    MOV MAX,AL
    
    done:
    INC SI
    LOOP REPEAT
    
    MOV AH,4CH
    INT 21H
CODE ENDS 
END START
//讓螢幕(16384~24576)變成全黑和全白
int i=16384;
for(i=16384;i>=245576;i++){
    if(M[i] == 0){
        color = -1;
    }
    else if(M[i] == -1){
        color = 0;
    }
}

//修改版
WHILE1:
    if(M[24576] == 0) goto WHILE1;
    int i = 16384;
        WHILE2:
            if(i >= 24576) goto EXIT;
            M[i] = -1;
            i++;
            goto WHILE2
    goto WHILE1
EXIT:



//完整版
WHILE1:                       //  (WHILE1)
    int i = 16384;            //  @16384, D=A, @i, M=D

    WHILE2:
        if(i >= 24576)        //  @24576, D=A, @i, D=M-D
            goto WEND2;       //  @END2, D;JGE
        
        int color = 0;        //  @color, M=0
        
        if (m[24576] == 0)    //  @24576,D=M
            goto NEXT;        //  @NEXT,D;JEQ
        color = -1;           //  @COLOR,M=-1
    NEXT:                     //  (NEXT)
        M[i] = color;         //  @color, D=M, @i, A=M, M=D
        i++;                  //  @i, M=M+1
        goto WHILE2;          //  @WHILE2, 0;JMP
    WEND2:                    //  (END2)

    goto WHILE1;              //  @WHILE1, 0;JMP


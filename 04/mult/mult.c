// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
#include <stdio.h>
int main(){
    int R0=5;
    int R1;
    int R2=0;
    //R0從0-5,R1從0-3,直到R2=15為止
    //不能用乘法來寫只能用加法
    for(R1=3;R1>0;R1--){
        R2=R2+5;
        printf("%d\n",R2);
    }
return 0;
    
}
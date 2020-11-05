#include<stdio.h>
/*
R0=1
while(1){
    R0=R0+1;
})
*/
int main(){
    int R0=1;                                    //@0,M=1
    /*while(1){
        R0=R0+1;                                 
        printf("R0=%d\n",R0);*/
LOOP:
    R0=R0+1;                                     //@0,M=M+1
    if(R0 == 10) goto EXIT;
    printf("RO=%d\n",R0);
    goto LOOP;                                   //@LOOP,0;JMP
    //}
EXIT:
    return 0;
}
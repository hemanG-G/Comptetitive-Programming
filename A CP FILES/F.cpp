//psdl lab

#include<stdio.h>
#include<stdlib.h>
#include<PIC18f4550.h>

void main(void){
    int tmp,i;
    
    int source[]  = {0x21,0x22,0x23,0x24};
    int dest[] = {0x00,0x00,0x00,0x00};
    for(i=0 ;i <4 ;i++){
        dest[i]=source[i];
    }
    return;
}
#include<stdio.h>
int main(void){
    union test{
        int a;
        char c[4];
    }; 
    union test hello;
    hello.a=0x123456;
    hello.c[1]=23;
    printf("%x\n",hello.a);
    return 0;
}
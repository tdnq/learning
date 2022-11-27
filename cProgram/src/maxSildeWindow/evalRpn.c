#include<stdio.h>
#include<stdlib.h>
int evalRpn(char **tokens,int tokensSize){
    int *pStack=(int*)malloc(tokensSize*sizeof(int));
    int top=-1;
    int row=0;
    int left=0;
    int right=0;
    for(;row<tokensSize;row++){
        if('+'==tokens[row][0]){
            right=pStack[top--];
            left=pStack[top--];
            pStack[++top]=left+right;
        }else if('-'==tokens[row][0]){
            right=pStack[top--];
            left=pStack[top--];
            pStack[++top]=left-right;
        }else if('*'==tokens[row][0]){
            right=pStack[top--];
            left=pStack[top--];
            pStack[++top]=left*right;
        }else if('/'==tokens[row][0]){
            right=pStack[top--];
            left=pStack[top--];
            pStack[++top]=left;
        }else
        {
            pStack[++top]=atio(tokens[row]);
        }
    }
    return pStack[top];
}
int main(void){
    struct Person{
        int age;
        char name[];
    };
    int a=1;
    struct Person *b;
    b=(struct Person*)malloc(sizeof(struct Person));
    struct Person *c;
    c=(struct Person*)calloc(1,sizeof(struct Person));
    return 0;
}
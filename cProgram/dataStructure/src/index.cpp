#include<iostream>
#include "./queue/queue.h"
#include"./stack/stackApplication.h"
using namespace leetCode;
int main(void)
{
    StackApplication test;
    vector<string>source={"4","13","5","/","+"};
    test.evalRPN(source);
    return 0;
}
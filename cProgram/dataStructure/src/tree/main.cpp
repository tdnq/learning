#include "./modules/Init/init.h"
#include<iostream>
using namespace leetCode;
int main(void){
    InitTrees initTree;
    int a[]={};
    TreeNode* temp=initTree.initTree(a,0,0);
    string res=initTree.serialize(temp);
    temp=initTree.deserialize(res);
    return 0;
}
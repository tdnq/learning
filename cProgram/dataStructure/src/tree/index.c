#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *initList(int len, int val[], int index)
{
    if (index >= len)
    {
        return NULL;
    }
    if (!val[index])
    {
        return NULL;
    }
    TreeNode *node;
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val[index];
    node->left = initList(len, val, 2 * index + 1);
    node->right = initList(len, val, 2 * index + 2);
    return node;
}
int main(void){
    char a[30];
    scanf("%s",&a);
    printf("%s\n",a);
    return 0;
}
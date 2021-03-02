#include<queue>
using namespace std;

struct  Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

void fillParent(struct Node *list){
    queue<struct Node*> tempQueue;
    list->parent=NULL;
    tempQueue.push(list);
    while(!tempQueue.empty()){
        struct Node *temp=tempQueue.front();
        //visit
        if(temp->left){
            temp->left->parent=temp;
        }
        if(temp->right){
            temp->right->parent=temp;
        }
        tempQueue.pop();
        if(temp->left){
            tempQueue.push(temp->left);
        }
        if(temp->right){
            tempQueue.push(temp->right);
        }
    }
}
int main(void){
    struct Node h1,h2,h3,h4;
    h1.data=1;
    h1.left=&h2;
    h1.right=&h3;
    h2.data=2;
    h2.right=NULL;
    h2.left=&h4;
    h3.data=3;
    h4.data=4;
    h3.left=h3.right=h4.right=h4.left=NULL;
    h1.parent=h2.parent=h3.parent=h4.parent=NULL;
    fillParent(&h1);
    return 0;
}
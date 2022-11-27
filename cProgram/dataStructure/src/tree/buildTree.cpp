#include<queue>
#include <vector>
#include <unordered_map>
using namespace std;
typedef struct TreeNode
        {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int nodeVal)
        {
            val = nodeVal;
            left = right = nullptr;
        }
    } TreeNode;
class BuildTree
{
private:
    int post_idx = 0;
    int prev_idx = 0;

    unordered_map<int, int> idx_map;

public:
    TreeNode *helperOfMidAndPost(vector<int> &midOrder, vector<int> &postOrder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int nodeVal = postOrder[--post_idx];
        TreeNode *node = new TreeNode(nodeVal);
        int index = idx_map[nodeVal];
        node->right = helperOfMidAndPost(midOrder, postOrder, index + 1, right);
        node->left = helperOfMidAndPost(midOrder, postOrder, left, index - 1);
        return node;
    }
    TreeNode *buildTreeFromMidAndPost(vector<int> &midOrder, vector<int> &postOreder)
    {
        for (auto val : midOrder)
        {
            idx_map[val] = post_idx++;
        }
        return helperOfMidAndPost(midOrder, postOreder, 0, (int)midOrder.size() - 1);
    }
    TreeNode *helperOfPrevAndMid(vector<int> &prevOrder, vector<int> &midOrder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int nodeVal = prevOrder[prev_idx++];
        int index = idx_map[nodeVal];
        TreeNode *node = new TreeNode(nodeVal);
        node->left = helperOfPrevAndMid(prevOrder, midOrder, left, index - 1);
        node->right = helperOfPrevAndMid(prevOrder, midOrder, index + 1, right);
        return node;
    }
    TreeNode *buildTreeFromPreviousAndMid(vector<int> &prevOrder, vector<int> &midOrder)
    {
        for (auto val : midOrder)
        {
            idx_map[val] = prev_idx++;
        }
        prev_idx = 0;
        return helperOfPrevAndMid(prevOrder, midOrder, 0, prevOrder.size() - 1);
    }
};
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node *next;
        Node(int nodeVal){
            val=nodeVal;
            left=right=nullptr;
        }
    };
class Init
{
private:

public:
    TreeNode *initTree(int data[], int size, int index)
    {
        if (!data[index])
        {
            return nullptr;
        }
        if (index >= size)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(data[index]);
        node->left = initTree(data, size, index * 2 + 1);
        node->right = initTree(data, size, index * 2+2);
        return node;
    }
    Node* initNodes(int data[],int size,int index){
       if (!data[index])
        {
            return nullptr;
        }
        if (index >= size)
        {
            return nullptr;
        }
        Node *node = new Node(data[index]);
        node->left = initNodes(data, size, index * 2 + 1);
        node->right = initNodes(data, size, index * 2+2);
        return node;
    }
};
class FillTree
{
private:

public:
    //perfect binary-tree
    Node *connect(Node*root){
       dfs(root,nullptr);
       return root;
    }
    void dfs(Node* node,Node *next){
        if(node){
            node->next=next;
            dfs(node->left,node->right);
            dfs(node->right,node->next!=nullptr?node->next->left:nullptr);
        }
    }
    //imperfect binary-tree
    Node *connectImperfectBinTree(Node* root){
        if(!root){
            return nullptr;
        }
        queue<Node*> temp;
        temp.push(root);
        while (!temp.empty())
        {
            int size=temp.size();
            Node *pre=nullptr;
            for(int i=1;i<=size;i++){
                Node *f=temp.front();
                temp.pop();
                if(f->left){
                    temp.push(f->left);
                }
                if(f->right){
                    temp.push(f->right);
                }
                if(i!=1){
                    pre->next=f;
                }
                pre=f;
            }
        }
        return root;
    }
};

int main()
{
    vector<int> a = {3, 9, 20, 15, 7};
    vector<int> b = {9, 3, 15, 20, 7};
    int data[]={1,2,3,4,0,0,7};
    Init init;
    Node* res= init.initNodes(data,sizeof(data)/sizeof(data[0]),0);
    FillTree fill;
    Node* res2=fill.connectImperfectBinTree(res);
    return 0;
}
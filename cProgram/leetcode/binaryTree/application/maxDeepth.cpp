/**
 * 题目:二叉树的最大深度
 * 思路:每递归一层就加一,返回最大深度.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        int maxDepth(TreeNode *root){
            if(root==nullptr){
                return 0;
            }
            int left=maxDepth(root->left);
            int right=maxDepth(root->right);
            return left>right?left+1:right+1;
        }
};
int main(void){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    Solution test;
    int res=test.maxDepth(root);
    return 0;
}

 
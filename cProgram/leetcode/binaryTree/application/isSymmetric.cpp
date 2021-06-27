class Solution{
    public:
        bool isSymmetric(TreeNode* root){
            if(root==nullptr){
                return true;
            }
            return isSymmetricHelper(root->left,root->right);
        }
        bool isSymmetricHelper(TreeNode* left,TreeNode * right){
            if(!left&&!right){
                return true;
            }
            if((left&&!right)||(!left&&right)){
                return false;
            }
            return left->val==right->val&&
                   isSymmetricHelper(left->left,right->right)&&
                   isSymmetricHelper(left->right,right->left);
        }
};
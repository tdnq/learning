#include "./functions.h"
#include"../Init/init.h"
namespace leetCode
{

    TreeFunctions::TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p)
        {
            return p;
        }
        if (root == q)
        {
            return q;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left)
        {
            return right;
        }
        if (!right)
        {
            return left;
        }
        if (left && right)
        {
            return root;
        }
        return nullptr;
    }

} // namespace leetCode
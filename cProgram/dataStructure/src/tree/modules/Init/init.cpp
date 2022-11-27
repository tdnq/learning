#include "./init.h"
namespace leetCode
{
    TreeNode *InitTrees::initTree(int data[], int size, int index)
    {
        if (index >= size)
        {
            return nullptr;
        }
        if (!data[index])
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(data[index]);
        node->left = initTree(data, size, index * 2 + 1);
        node->right = initTree(data, size, index * 2 + 2);
        return node;
    }
    string InitTrees::serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "[]";
        }
        string res = "[";
        queue<TreeNode *> temp;
        temp.push(root);
        while (!temp.empty())
        {
            TreeNode *front = temp.front();
            temp.pop();
            //visit operation
            if (!front->val)
            {
                res += "null,";
            }
            else
            {
                res += to_string(front->val) + ',';
            }
            if (front->left)
            {
                temp.push(front->left);
            }
            if (front->right)
            {
                temp.push(front->right);
            }
        }
        res.replace(res.size() - 1, 1, "]");
        return res;
    }
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        int len = data.size();
        int res[(len - 2 + 1) / 2];
        string temp = "";
        int i = 1, j = 0;
        for (; i < len - 1; i++)
        {
            if (data[i] != ',')
            {
                temp += data[i];
            }
            else
            {
                res[j] = std::stoi(temp);
                j++;
                temp.erase(0);
            }
        }
        return initTree(res, j + 1, 0);
    }
} // namespace leetCode
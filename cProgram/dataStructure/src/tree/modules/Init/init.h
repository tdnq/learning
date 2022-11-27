#ifndef INITTREE
#define INITTREE
#include <string>
#include <queue>
using std::queue;
using std::string;
using std::to_string;
namespace leetCode
{
    struct TreeNode
    {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int nodeVal)
        {
            val = nodeVal;
            left = right = nullptr;
        }
    };
    class InitTrees
    {
    public:
        TreeNode *initTree(int data[], int size, int index);
        string serialize(TreeNode *root);
        TreeNode *deserialize(string data);
    };

    //temporary modules
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
            if (front)
            {
                res += to_string(front->val) + ',';
                temp.push(front->left);
                temp.push(front->right);
            }else
            {
                res += "null,";
            }
            
        }
        res.replace(res.size() - 1, 1, "]");
        return res;
    }
    TreeNode *InitTrees::deserialize(string data)
    {
        if (data.size()==2)
        {
            return nullptr;
        }
        int len = data.size();
        data[len-1]=',';
        int res[(len - 2 + 1) / 2];
        string temp = "";
        int i = 1, j = 0;
        for (; i < len; i++)
        {
            if (data[i] != ',')
            {
                temp += data[i];
            }
            else
            {
                if(!temp.compare("null")){
                   temp.replace(0,temp.size(),"0");
                }
                res[j] = std::stoi(temp);
                j++;
                temp.erase(0);
            }
        }
        return initTree(res,j,0);
    }
} // namespace leetCode

#endif
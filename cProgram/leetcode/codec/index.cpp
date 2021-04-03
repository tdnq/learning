#include<string>
using std::string;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Codec{
    private:
        int pos;
        TreeNode * deserializeHelper(string str){
            string temp="";
            while (pos<str.size()&&str[pos]!=',')
            {
                temp+=str[pos++];
            }
            pos++;
            if(temp.compare("X")==0){
                return nullptr;
            }
            TreeNode * root=new TreeNode(std::stoi(temp));
            root->left=deserializeHelper(str);
            root->right=deserializeHelper(str);
            return root;
        }
    public:
        string serialize(TreeNode* root){
            if(root==nullptr){
                return "X";
            }
            string left=serialize(root->left);
            string right=serialize(root->right);
            return std::to_string(root->val)+","+left+","+right;
        }
        TreeNode *deserialize(string str){
            pos=0;
            return deserializeHelper(str);
        }
};

int main(){
    TreeNode temp(0);
    temp.val=12;
    Codec test;
    string res= test.serialize(&temp);
    TreeNode *root=test.deserialize(res);
    return 0;
}
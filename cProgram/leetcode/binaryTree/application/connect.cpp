#include<queue>
using std::queue;
class Solution{
    public:
        Node * connect(Node * root){
            dfs(root,nullptr);
            return root;
        }
        Node *connect2(Node *root){
            levelOrderTraversal(root);
            return root;
        }
        void dfs(Node*root,Node*next){
            if(root==nullptr){
                return;
            }
            root->next=next;
            dfs(root->left,root->right);
            dfs(root->right,root->next?root->next->left:nullptr);
        }
        void levelOrderTraversal(Node *root){
            if(!root){
                return root;
            }
            queue<Node*> q;
            q.push(root);
            while (!q.empty())
            {
                int size=q.size();
                Node * pre=nullptr;
                for(int i=0;i<size;i++){
                    Node* tar=q.front();
                    q.pop();
                    if(i<size-1){
                        tar->next=q.front();
                    }else{
                        tar->next=nullptr;
                    }
                    if(tar.left){
                        q.push(tar->left);
                    }
                    if(tar.right){
                        q.push(tar->right)
                    }
                }
            }
        }
};
#include <climits>
namespace leetCode{
    class MinStack{
        private:
            struct node{
                int val;
                node* next;
                node(int nodeVal){
                    val=nodeVal;
                    next=nullptr;
                }
            };
            struct headNode{
                node*front;
                node*rear;
                headNode(){
                     front=rear=nullptr;
                }
            };
            headNode *head;
        public:
        MinStack(){
            head=new headNode();
        }
        void push(int val){
            node* newNode=new node(val);
            newNode->next=head->front;
            head->front=newNode;
            if(head->rear==nullptr){
                head->rear=newNode;
            }
        }
        void pop(){
            if(head->front==nullptr){
                return;
            }else if(head->front==head->rear){
                node*temp=head->front;
                head->front=head->rear=nullptr;
                delete(temp);
            }else{
                node*temp=head->front;
                head->front=temp->next;
                delete(temp);
            }
        }
        int top(){
            return head->front->val;
        }
        int getMin(){
            int min=INT_MAX;
            node*temp=head->front;
            while (temp)
            {
                min=temp->val<min?temp->val:min;
                temp=temp->next;
            }
            return min;
        }
    };
    
}
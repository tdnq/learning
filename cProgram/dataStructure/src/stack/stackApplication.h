#include<string>
#include<stack>
#include<vector>
using std::stack;
using std::vector;
using std::string;
namespace leetCode{

class StackApplication
{
private:

public:
    vector<int> dailyTemperatures(vector<int>&temperatures){
        int len=temperatures.size();
        vector<int>res(len,0);
        stack<int>temp;
        for(int i=0;i<len;i++){
            while (!temp.empty()&&temperatures[i]>temperatures[temp.top()])
            {
                auto t=temp.top(); temp.pop();
                res[t]=i-t;
            }
            temp.push(i);
        }
        return res;
    }
    int evalRPN(vector<string>tokens){
        if(tokens.empty()){
            return 0;
        }
        stack<int> temp;
        int len=tokens.size();
        for (int i = 0; i < len; i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=temp.top();
                temp.pop();
                int b=temp.top();
                temp.pop();
                int val =calculation(b,a,tokens[i]);
                temp.push(val);
            }else{
                temp.push(std::stoi(tokens[i]));
            }
        }
        return temp.top();
    }
    int calculation(int a,int b,string operation){
        if(operation=="+"){
            return a+b;
        }else if(operation=="-"){
            return a-b;
        }else if(operation=="*"){
            return a*b;
        }else{
            return a/b;
        }
    }
};
}

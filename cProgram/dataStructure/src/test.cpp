#include<iostream>
using namespace std;
class test{
    public:
        void fun1();
        void fun2();
};
void test::fun1(){
    cout<<1<<endl;
}
void test::fun2(){
    cout<<2<<endl;
    fun1();
}

int main(){
    bool te="fa"=="fa";
    return 0;
}
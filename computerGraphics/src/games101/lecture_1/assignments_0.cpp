// taste eigen3
#include<eigen3/Eigen/Core>
#include<iostream>
#include<cmath>
#include<eigen3/Eigen/Dense>
using namespace std;
int main(){
    cout<<"just a test\n";
    float a=1.0,b=2.0;
    cout<<a<<endl;
    cout<<a/b<<endl;
    cout<<sqrt(a)<<endl;
    cout<<acos(-1)<<endl;
    
    cout<<"example of vector"<<endl;
    Eigen::Vector3f v(1.0,2.0,3.0);
    Eigen::Vector3f w(1.0,2.0,3.0);
    cout<<v<<endl;

    cout<<"example of addtion\n";
    cout<<v+w<<endl;
    cout<<"example of multiply\n"<<v*3.0f<<endl;

    return 0;
}
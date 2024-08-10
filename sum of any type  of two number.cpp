// write a program to find the sum of any type of two number
#include <iostream>
using namespace std;
class sum{

public:
 void input(int,int);
 void input(float,float);
 void input(double,double);
 void input(int,float);
 void input(int,double);
 void input(float,double);
 void input(float,int);
 void input(double,int);

};
void sum::input(int a,int b){
    cout<<"sum of two integer number is : "<<a+b<<endl;
}
void sum::input(float a,float b){
    cout<<"sum of two float number is : "<<a+b<<endl;
}
void sum::input(double a,double b){
    cout<<"sum of two double number is : "<<a+b<<endl;
}
void sum::input(int a,float b){
    cout<<"sum of one integer and one float number is : "<<a+b<<endl;
}
void sum::input(int a,double b){
    cout<<"sum of one integer and one double number is : "<<a+b<<endl;
}
void sum::input(float a,double b){
    cout<<"sum of one float and one double number is : "<<a+b<<endl;
}
void sum::input(float a,int b){
    cout<<"sum of one float and one integer number is : "<<a+b<<endl;
}
void sum::input(double a,int b){
    cout<<"sum of one double and one integer number is : "<<a+b<<endl;
}
int main(){
    sum s;
    s.input(10,20);
    s.input(10.5,20.5);
    s.input(10.5,20);
    s.input(10,20.5);
    s.input(10,20.5);
    s.input(10.5,20);
    s.input(10.5,20);
    s.input(10,20.5);
    return 0;
}


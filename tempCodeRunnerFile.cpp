#include<iostream>
using namespace std;

class base{
    public:
    void show(){
         cout<<"base class show function called !!!"<<endl;
    }
};

class drive:public base{
    public:
       void show(){
         cout<<"drive class show function called !!!"<<endl;
    }

};

int main(){
    drive ob;
    ob.show();
    b1=&ob;
    return 0;
} 
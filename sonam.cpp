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
    base  *b1;
    drive ob;
    b1=&ob;
    ob.show();
    
    return 0;
} 
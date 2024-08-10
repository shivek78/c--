#include<iostream>
using namespace std;

class base{
    public:
    int x,y;
    base(){
        cout<<"base class default construtior called"<<endl;
    }

    base(int x){
        cout<<"base class default construtior called"<<endl;
    }
};
class drive:public base{
    public:
    string name,email;
     drive():base(12){
         cout<<"drive class default construtior called"<<endl;
      }

      drive(int x):base(x){
         cout<<"drive class default construtior called"<<endl;
      }
};
int main(){
    drive obj1=drive(12);
    drive obj2=drive();
    return 0;
}
#include<iostream>
using namespace std;

class base{
    public:
    int x,y;
    base(){
        cout<<"base class default construtior called"<<endl;
    }
};
class drive:public base{
    public:
    string name,email;
     drive(){
         cout<<"drive class default construtior called"<<endl;
      }
};
int main(){
    drive obj;
    obj.x=100;
    cout<<obj.x;
    return 0;
}
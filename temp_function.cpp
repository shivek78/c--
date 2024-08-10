#include<iostream>
using namespace std;

template<typename T1,typename T2>
class calculator{
    T1 x;
    T2 y;

    public:
    calculator(T1 x,T2 y){
           this->x=x;
           this->y=y;
    }

    void subtraction(){
        cout<<"sum="<<x-y<<endl;
    }

    void multiplication(){
        cout<<"sum="<<x*y<<endl;
    }

    void Division(){
        cout<<"sum="<<x/y<<endl;
    }

    void Addition(){
        cout<<"sum="<<x+y<<endl;
    }


};

int main(){
    calculator<int,int>ob(11,22);
    ob.Addition();
    ob.subtraction();
    ob.multiplication();
    ob.Division();

    return 0;
}

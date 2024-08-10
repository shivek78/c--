#include <iostream>
using namespace std;
template<typename T>
 T Max (T x,T y){
   if(x>y){
       return x;
   }
     else{
       return y;
   }
}
template<typename T1, typename T2>

void sum (T1 x, T2 y){
	cout<<"sum="<<x+y<<endl;
}
int main()
{
    cout<<Max<int>(10,20)<<endl;
    cout<<Max<float>(10.5f,20.5f)<<endl;
    sum<int,int>(10,20);
    
    sum<float,double>(10.5f,20.5f);
   

    return 0;
}



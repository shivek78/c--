/*about the templete and templet keyword
templete  is very useful keyword in c++ programming. It is used to define a generic class or function
 a templete is very power full tools 
 the  simple is to pass data type  as  parameter so that we can use a single class or function for different data type
 */
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
int main()
{
    cout<<Max<int>(10,20)<<endl;
    cout<<Max<float>(10.5f,20.5f)<<endl;
   

    return 0;
}


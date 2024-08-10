//swaping of two number using template
#include <iostream>
using namespace std;
template<typename T>

void swap(T x,T y)
{
	cout<<"before swaping  x="<<x<<endl;
		cout<<"before swaping  y="<<y<<endl;
			
	
T temp
  temp=x;
  x=y;
  y=temp;
  

 
}
int main(){
	cout<<swap<int>(10,20)<<endl;
}



    return 0;
}



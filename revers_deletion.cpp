//
#include<iostream>
 using namespace std;
 int main()
 {
  
  
  int* p1=new int[10];
  int* p2=new int[20];
  int* p3=new int[30];

 cout<<*p1<<"\t"<<*p2<<"\t"<<*p3<<endl;
 delete p3;
 delete p2;
 delete p1;
    cout<<*p1<<"\t"<<*p2<<"\t"<<*p3<<endl;
    
  return 0;
  }
  

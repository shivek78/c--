 //pointer concept
 #include<iostream>
 using namespace std;
 int main()
 {
  // decealer the pointer
  int *ptr=new int;//variable
  *ptr=10;
  cout<<" the address of the variable"<<&ptr<<endl;// output is address
  
  cout<<" the address of the variable"<<ptr<<endl;//output is address
  cout<<" the address of the variable"<<*ptr<<endl;//output is value 10
  
  return 0;




 }

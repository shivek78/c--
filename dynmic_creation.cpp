//pointer concept
// with indexing feture

 #include<iostream>
 using namespace std;
 int main()
 {
  // decealer the pointer
 int *arr=new int[5];//dynmic arrya creation
 int i;
 cout<<"enter arary elemente";
 for(i=0;i<5;i++)
 {
 cin>>*(arr+i);
 	
 }
 cout<<"apply elements are";
 for(i=0;i<5;i++)
 {
cout<<*(arr+i)<<"\t";
 
 }

  return 0;
}

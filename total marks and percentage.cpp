#include<iostream>
#include<math.h>
using namespace std;
int main () {
	int c,d,e,f,a,b,sum ,g,h,i,j,k,total, per,percentage;
	cout<<"enter you  first subject marks number ";
	cin>>a;
	cout<<"enter you  first subject total marks ";
	cin>>f;
	
	cout<<"enter  your second  subject marks number ";
	cin>>b;
	cout<<"enter you  second subject  total marks  ";
	cin>>g;
	
	cout<<"enter you  third subject marks number ";
	cin>>c;
	cout<<"enter you  third subject  total marks  ";
	cin>>h;
	
	cout<<"enter  your  fourth  subject marks number ";
	cin>>d;
	cout<<"enter you  fourth subject  total marks  ";
	cin>>i;
	
	cout<<"enter  your  fivth subject marks number ";
	cin>>e;
	cout<<"enter you  fivth subject  total marks  ";
	cin>>j;
	cout<<" your total marks = ";
		
	sum=(a+b+c+d+e);
	cout<<sum<<endl;
	//total
	total=(f+g+h+i+j);
	cout<<"total of all subject="<<total<<endl;
	//per
	per=(sum*100)/total;
		cout<<"percentage =";
	cout<<per;

	
	
	return 0;
	
	
}

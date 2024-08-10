#include<iostream>
using namespace std;
int main () {
	int add,sub,multi,div,a,b;
	cout<<"enter first number ";
	cin>>a;
	cout<<"enter second number ";
	cin>>b;
	//addition
	add= a+b;
	cout<<"add two numbers= "<< add <<endl;
	//substraction
	sub= a-b;
	cout<<"sub two numbers= " << sub <<endl;
	
	// multiplication
	multi=(a*b);
	cout<<"multi two numbers= " << multi <<endl;

	// division
	div= a/b;
	cout<<"div two numbers= "<< div <<endl;
	
	return 0;
}

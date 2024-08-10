#include <iostream>
using namespace std;
class Base {
	public :
		int x;
		Base(){
			cout<<"base class default constructor called!!!"<<endl;
		}
		Base(int x){
			cout<<"base class paramiterized constructor is called !!!"<<endl;
		} 
};
class Drive:public Base{
	public :
		int y;
		Drive (){
			cout<<"Drive class default contructor is called!!!"<<endl;
		}
		Drive(int y){
			cout<<"Drive parameterized constructor is called !!!"<<endl;
			
		}
		
};
int main(){
	Drive ob;
	Base obj(77);
	return 0;
}

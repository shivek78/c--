#include<iostream>
using namespace std;

class node{
	public:
	node *prev;
	int data;
	node *next;
	node(int data=0){
	this->	prev=NULL;
		this->data=data;
	this->	next=NULL;
	}
};

class doublylinkedlist{
	node *head=NULL;
	public:
	void insertnodeinbeg(int value){

	}
	void insertnodeatend(int value){

	}
	void insertnodeatanyloc(int pos,int value){

	}
	void deletenode(int pos){

	}
	void displaylist(){

	}
};

int main(){
   doublylinkedlist list;
	while(true)
    {
		system("cls");
		cout<<"\t** Singly Linked List **\n"<<endl;
		cout<<"\t1 Insert Node In Begining"<<endl;
		cout<<"\t2 Insert Node At End"<<endl;
		cout<<"\t3 Insert Node At Any Location"<<endl;
		cout<<"\t4 Delete Node"<<endl;
		cout<<"\t5 Display List"<<endl;
		cout<<"\t6 Exit\n"<<endl;
		int choice,val,pos;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice)
        {
			case 1:
				cout<<"Enter value";
				cin>>val;
				list.insertnodeinbeg(val);
				break;
			case 2:
        cout<<"Enter value";
				cin>>val;
				list.insertnodeatend(val);                
				break;
			case 3:
        cout<<"Enter Position: ";
				cin>>pos;
        cout<<"Enter value: ";
				cin>>val;
				list.insertnodeatanyloc(pos,val);
				break;
			case 4:
				break;
			case 5:
				list.displaylist();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Invalid Choice !!!!!"<<endl;
		}
		cout<<"\n\n";
		system("pause");
	}
	return 0;
}

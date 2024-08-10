#include<iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node(int val=0)
    {
        data=val;
        next=NULL;
        
    }
};
class Singlylinkedlist
{
    public:
    Node *head=NULL;
    void insertnodeinbeg()
    {
        Node *newnode= new Node(value);  //meamory allocated name as newnode and its address is value
        if(head==NULL)
        {
            head= newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
        void displaylist()
        {
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
            }
            else
            Node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data;
                temp=temp->next;
            }
        }
    }
};
int main(){
	while(true){
		system("cls");
		cout<<"\t******* Singly Linked List *********\n"<<endl;
		cout<<"\t1 Insert Node In Begining"<<endl;
		cout<<"\t2 Insert Node At End"<<endl;
		cout<<"\t3 Insert Node At Any Location"<<endl;
		cout<<"\t4 Delete Node"<<endl;
		cout<<"\t5 Display List"<<endl;
		cout<<"\t6 Exit\n"<<endl;
		int choice;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
			cout<<"enter value";
			
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
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
}

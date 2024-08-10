#include <iostream>
#include <list>
#include <string>

using namespace std;
bool check(string name)
{if (name[0]=='r')
return true;
else
 return false;
}

int main()
{
   
    list<string> mylist = {"shivek", "raju","raju", "raju", "sonam", "vicky", "pandit", "rahul", "thakur", "siri", "bablu"};
    list<string>mylist2{"aaaa","bbb","rrrr","sss","jjjj","vvvv","cccc"};
    
    mylist.merge(mylist2);
    cout<<"\n\n list elements are:"<<endl;
    for(string name:mylist){
    	cout<<name<<" ";
	}
   
    return 0;
}


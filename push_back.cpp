#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<string> mylist;

    cout << "Enter five student names:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        string name;
        cin >> name;
        mylist.push_back(name);
    }

    cout << "List elements:" << endl;
    for (const string& name : mylist)
    {
        cout << name << "\t";
    }

    return 0;
}


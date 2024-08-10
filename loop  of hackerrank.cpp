#include <iostream>
using namespace std;
string b(int num) {
string a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return a[num];
}

int main() {
    // Input
    int start, end;
 cin >> start >> end;

    // Loop through the range
    for (int i = start; i <= end; ++i)
     {
        if (1 <= i && i <= 9)
         {
            cout << b(i) << endl;
        }
         else if (i % 2 == 0)
          {
            cout << "even" <<endl;
        }
         else
       {
        cout << "odd" <<endl;
        }
    }

    return 0;
}


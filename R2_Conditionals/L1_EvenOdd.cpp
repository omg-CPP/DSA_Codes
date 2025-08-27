#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    if(num % 2 == 0)
    {
        cout<<num<<" is Even Number";
    }
    else
    {
        cout<<num<<" is Odd Number";
    }
    return 0;
}

// Enter the number : 6
// 6 is Even Number

// Enter the number : 9
// 9 is Odd Number
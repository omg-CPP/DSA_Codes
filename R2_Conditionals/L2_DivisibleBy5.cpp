#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    if(num % 5 == 0)
    {
        cout<<num<<" is Divisible by 5";
    }
    else
    {
        cout<<num<<" is not Divisible by 5";
    }
    return 0;
}

// Enter the number : 35
// 35 is Divisible by 5

// Enter the number : 47
// 47 is not Divisible by 5
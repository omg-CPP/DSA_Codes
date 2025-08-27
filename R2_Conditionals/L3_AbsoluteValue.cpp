#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    if(num > 0)
    {
        cout<<num<<" is Positive"<<endl;
        cout<<"Absolute Value : "<<num;
    }
    else if(num == 0)
    {
        cout<<num<<" is Non-negative"<<endl;
        cout<<"Absolute Value : "<<num;
    }
    else // num < 0
    {
        cout<<num<<" is Negative"<<endl;
        cout<<"Absolute Value : "<<(-num);
    }
    return 0;
}

// Enter the number : 5
// 5 is Positive
// Absolute Value : 5

// Enter the number : 0
// 0 is Non-negative
// Absolute Value : 0

// Enter the number : -63
// -63 is Negative
// Absolute Value : 63
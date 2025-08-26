#include <iostream>
using namespace std;
int main()
{
    // Take float input and print the fractional part of the real number.
    // OR Print the Greatest Integer Number of any Real Number.
    // {x} = x - [x]
    float x;
    cout<<"Enter a real number : ";
    cin>>x; 
    cout<<x<<endl; // 9.8
    int y = (int)x;
    if(y < 0)
    {
        y = y - 1;
    }
    cout<<"Integer Part : "<<y<<endl; // Integer Part : 9
    float z = (float)y;
    x = x - z; // {x} = x - [x]
    cout<<"Fractional Part : "<<x<<endl; // Fractional Part : 0.8
    return 0;
}

// Enter a real number : 9.8
// 9.8
// Integer Part : 9
// Fractional Part : 0.8

// Enter a real number : -1.3
// -1.3
// Integer Part : -2
// Fractional Part : 0.7
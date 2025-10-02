#include <iostream>
using namespace std;
int main()
{
    int x = 4;
    int* p = &x;
    cout<<x<<endl; // 4 : value of x
    cout<<&x<<endl; // 0x61ff08 : address of x
    cout<<p<<endl; // 0x61ff08 : address of x
    cout<<&p<<endl; // 0x61ff08 : address of pointer variable

    float y = 4.3;
    cout<<y<<endl; // 4.3
    float* q = &y;
    cout<<&y<<endl; // 0x61ff04
    cout<<q<<endl; // 0x61ff04
    cout<<&q<<endl; // 0x61ff00
    return 0;
}
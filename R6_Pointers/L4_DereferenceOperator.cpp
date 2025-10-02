#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    int* p = &x;
    cout<<x<<endl; // 10
    cout<<&x<<endl; // 0x61ff0c
    cout<<p<<endl; // 0x61ff0c
    cout<<&p<<endl; // 0x61ff08
    // Dereference Operator
    cout<<*p<<endl; // 10

    x = 15;
    cout<<x<<endl; // 15
    cout<<*p<<endl; // 15

    *p = 6;
    cout<<x<<endl; // 6
    cout<<*p<<endl; // 6
    return 0;
}
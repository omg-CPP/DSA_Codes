#include <iostream>
using namespace std;
int main()
{
    // increment and decrement
    int x = 7;
    int* ptr = &x;
    cout<<x<<endl; // 7
    cout<<ptr<<endl; // 0x61ff08
    ptr = ptr + 1;
    cout<<ptr<<endl; // 0x61ff0c
    // 08 -> 0c : difference of 4 bytes
    // Number System
    // 0 1 2 3 4 5 6 7 8 9 a b c d e f
    // 10 to 16
    ptr = ptr - 1;
    cout<<ptr<<endl; // 0x61ff08

    bool flag = true;
    bool* p = &flag;
    cout<<p<<endl; // 0x61ff03
    p++;
    cout<<p<<endl; // 0x61ff04

    int a = 4;
    int* pt = &a;
    cout<<a<<endl; // 4
    cout<<*pt<<endl; // 5
    pt = pt + 1;
    cout<<*pt<<endl; //  23199496

    int b = 5;
    int* ptrr = &b;
    cout<<b<<endl; // 5
    cout<<*ptrr<<endl; // 5
    (*ptrr)++; // *ptrr = *ptrr + 1;
    cout<<*ptrr<<endl; // 6
    (*ptrr)--; // *ptrr = *ptrr - 1;
    cout<<*ptrr<<endl; // 5
    return 0;
}
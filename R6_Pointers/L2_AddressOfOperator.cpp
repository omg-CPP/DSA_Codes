#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    cout<<x<<endl; // 5 : Value of x
    cout<<&x<<endl; // 0x61ff0c : Address of x
    // memory is allocated at run time
    return 0;
}
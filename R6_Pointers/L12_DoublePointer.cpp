#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    cout<<x<<endl; // 5
    cout<<&x<<endl; // 0x61ff08

    int* ptr1 = &x;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;

    cout<<ptr1<<" "<<ptr2<<" "<<ptr3<<endl;
    // 0x61ff08 0x61ff04 0x61ff00

    cout<<*ptr1<<endl; // 5

    cout<<*ptr2<<endl; // 0x61ff08
    cout<<**ptr2<<endl; // 5
    
    cout<<*ptr3<<endl; // 0x61ff04
    cout<<**ptr3<<endl; // 0x61ff08
    cout<<***ptr3<<endl; // 5
    return 0;
}
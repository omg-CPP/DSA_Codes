#include <iostream>
using namespace std;
int main()
{
    int x = 6;
    int y = 7;
    int* p1 = &x;
    int* p2 = &y;
    int sum = *p1 + *p2;
    cout<<sum<<endl; // 13

    int a, b;
    int* ptr1 = &a;
    int* ptr2 = &b;
    cout<<"Enter first number : ";
    cin>>*ptr1;
    cout<<"Enter second number : ";
    cin>>*ptr2;
    cout<<(*ptr1 + *ptr2)<<endl;
    // cout<<a+b<<endl;
    // Enter first number : 5
    // Enter second number : 4
    // 9


    return 0;
}
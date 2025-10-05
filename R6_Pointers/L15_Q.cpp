// Predict the output of the following code snippet.

#include <iostream>
using namespace std;
int main()
{
    int a = 15, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    cout<<a<<" "<<b<<endl; // 15 20
    *ptr1 = *ptr2;
    // a gets the value of b
    cout<<a<<" "<<b<<endl; // 20 20
    return 0;
}

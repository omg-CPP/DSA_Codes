#include <iostream>
using namespace std;
// creating swap function will not work here
// as they are pass by value not by reference
// No swapping takes place
void swapFunction(int a, int b) {
    int temp = a;
    a = b;
    b = a;
    return;
}
int main()
{
    int a = 5;
    int b = 4;
    cout<<a<<" "<<b<<endl; // 5 4
    swapFunction(a,b);
    cout<<a<<" "<<b<<endl; // 5 4
    return 0;
}
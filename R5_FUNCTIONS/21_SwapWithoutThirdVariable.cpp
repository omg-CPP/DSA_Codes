#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int b = 4;
    cout<<a<<" "<<b<<endl; // 5 4
    a = a + b; // a = 5 + 4 = 9
    b = a - b; // b = 9 - 4 = 5
    a = a - b; // a = 9 - 5 = 4
    cout<<a<<" "<<b<<endl; // 4 5
    return 0;
}
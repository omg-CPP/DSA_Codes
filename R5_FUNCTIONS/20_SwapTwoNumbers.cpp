#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int b = 4;
    cout<<a<<" "<<b<<endl; // 5 4
    int temp = a; // temp = 5
    a = b; // a = 4
    b = temp; // b = 5
    cout<<a<<" "<<b<<endl; // 4 5
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int a = 1;
    int b = 2;
    int z = a++ + --a + b-- + ++b + a--;
    cout<<z<<endl; // 7
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    bool flag = true;
    cout<<flag<<endl; // 1
    flag = false;
    cout<<flag<<endl; // 0

    // for non-zero values ans = 1
    // for zero values ans = 0
    bool x = -3;
    cout<<x<<endl; // 1
    bool y = 0;
    cout<<y<<endl; // 0
    bool z = 1;
    cout<<z<<endl; // 1
    bool t = 5;
    cout<<t<<endl; // 1
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    float x = 3.1;
    // Used for all real number values
    x = x + 1;
    cout<<x<<endl; // 4.1

    float a = 5;
    float b = 2;
    cout<<a+b<<endl; // 7
    cout<<a-b<<endl; // 3
    cout<<a*b<<endl; // 10
    cout<<a/b<<endl; // 2.5

    cout<<5/2<<endl; // 2
    cout<<5.0/2<<endl; // 2.5
    cout<<5/2.0<<endl; // 2.5
    cout<<5.0/2.0<<endl; // 2.5

    cout<<5.12+4<<endl; // 9.12

    // int h = 2.1;
    // cout<<h<<endl; // 2 => Implicit Conversion

    // float g = 5;
    // cout<<g<<endl; // 5

    cout<<5.0<<endl; // 5
    cout<<3.1415<<endl; // 3.1415

    float d = 2/7;
    cout<<d<<endl; // 0
    return 0;
}
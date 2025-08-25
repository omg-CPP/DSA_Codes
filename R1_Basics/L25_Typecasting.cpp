#include <iostream>
using namespace std;
int main()
{
    float x = 7.1;
    int y;
    y = (int)x;
    cout<<y<<endl; // 7

    bool a = true;
    cout<<a+9<<endl; // 10
    int b;
    b = (int)a;
    cout<<b<<endl; // 1

    char ch = 'A';
    cout<<ch+100<<endl; // 165
    int z = (int)ch;
    cout<<ch<<" : "<<z<<endl; // A : 65
    return 0;
}
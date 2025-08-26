#include <iostream>
using namespace std;
int main()
{
    // Each character has an ASCII Value
    char ch = 'A';
    cout<<ch<<" : "<<(int)ch<<endl; // A : 65
    cout<<(int)('Z')<<endl; // 90

    char x = 'a';
    cout<<x<<" : "<<(int)x<<endl; // a : 97
    cout<<(int)('z')<<endl; // 122

    char y = '0';
    cout<<y<<" : "<<(int)y<<endl; // 0 : 48
    cout<<(int)('9')<<endl; // 57
    return 0;
}
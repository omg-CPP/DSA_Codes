#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "abcdef";
    cout<<str<<endl; // abcdef
    cout<<str.substr(1)<<endl; // bcdef
    cout<<str.substr(1,3)<<endl; // bcd
    cout<<str.substr(0,4)<<endl; // abcd
    return 0;
}
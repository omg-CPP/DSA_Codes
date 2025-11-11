#include <iostream>
using namespace std;
// print second half of string using substring function
int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<s<<endl;
    // n = 8 : even
    int len = s.length();
    cout<<s.substr(len/2)<<endl;
    return 0;
}

// Enter string : abcdef
// abcdef
// def

// Enter string : abcdefgh
// abcdefgh
// efgh
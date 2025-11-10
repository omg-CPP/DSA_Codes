#include <iostream>
#include <string>
using namespace std;
int main()
{
    // String as a datatype
    string str = "Om Gupta";
    // character array of size = 9 including null character
    cout<<str<<endl; // Om Gupta
    cout<<str[0]<<endl; // O
    cout<<str.size()<<endl; // 8

    // string s;
    // // only if given string has no spaces
    // cout<<"Enter String : ";
    // cin>>s;
    // cout<<s<<endl; // Om

    string st;
    cout<<"Enter the string : ";
    getline(cin,st);
    cout<<st<<endl;
    // Enter the string : Om Gupta
    // Om Gupta
    return 0;
}
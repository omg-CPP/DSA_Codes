#include <iostream>
using namespace std;
int main()
{
    char ch = 'A';
    // character array = Strings
    char str[5] = {'a','b','c','d','e'};
    for(int i = 0 ; i < 5 ; i++) {
        cout<<str[i]<<" ";
    }
    // a b c d e 
    cout<<endl;

    // String
    cout<<"My name is Om Gupta"<<endl;
    // My name is Om Gupta

    char c = '\n';
    cout<<c<<endl;
    cout<<(int)c<<endl; // 10

    char h = '\0';
    cout<<h<<endl;
    cout<<(int)h<<endl; // 0

    char st[6] = {'a','b','c','d','e'};
    cout<<(int)(st[0])<<endl; // 97
    cout<<(int)(st[4])<<endl; // 101
    cout<<(int)(st[5])<<endl; // 0 -> '\0'

    return 0;
}
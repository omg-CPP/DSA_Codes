#include <iostream>
using namespace std;
int main()
{
    char str[] = {'a','b','c','d','e'};
    for(int i = 0 ; str[i] != '\0' ; i++) {
        cout<<str[i]<<" ";
    }
    // a b c d e  
    cout<<endl;
    cout<<str<<endl; // abcde -> String

    char st[] = {'a','b','\0','d','e'};
    cout<<st<<endl; // ab
    return 0;
}
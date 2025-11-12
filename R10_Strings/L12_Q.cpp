// Input a string of size n and update all the odd positions in the string to character ‘#’. Consider
// 0-based indexing.
#include <iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    cout<<str<<endl;
    for(int i = 0 ; str[i] != '\0' ; i++) {
        if(i % 2 != 0) {
            str[i] = '#';
        }
    }
    cout<<str<<endl;
    return 0;
}

// Enter string : Pbwcshkuiglhlds
// Pbwcshkuiglhlds
// P#w#s#k#i#l#l#s
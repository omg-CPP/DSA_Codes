// Input a string of even length and reverse the second half of the string.
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    cout<<str<<endl;
    string s = str;
    int len = str.length();
    if(len % 2 != 0) {
        cout<<"Invalid Input"<<endl;
    }
    else { // len == even
        reverse(str.begin()+len/2,str.end());
    }
    cout<<str<<endl;
    return 0;
}

// Enter string : abcdefgh
// abcdefgh
// abcdhgfe
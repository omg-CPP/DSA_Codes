#include <iostream>
#include <algorithm>
using namespace std;
// Input a string of even length and reverse the first half of the string
int main()
{
    // if n is even
    // 0 ---- n-1
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    cout<<str<<endl;
    int len = str.length();
    reverse(str.begin()+0,str.begin()+len/2);
    cout<<str<<endl;
    return 0;
}

// Enter string : abcdefgh
// abcdefgh
// dcbaefgh

// Enter string : raghav
// raghav
// garhav

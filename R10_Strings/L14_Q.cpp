// Check whether the given string is palindrome or not.
#include <iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    cout<<str<<endl;
    string s = str;
    int len = str.length();
    int i = 0;
    int j = len-1;
    while(i <= j) {
        char temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    if(s == str) {
        cout<<"String is Palindrome"<<endl;
    }
    else {
        cout<<"String is not a Palindrome"<<endl;
    }
    return 0;
}

// Enter string : abcde
// abcde
// String is not a Palindrome

// Enter string : abcdcba
// abcdcba
// String is Palindrome
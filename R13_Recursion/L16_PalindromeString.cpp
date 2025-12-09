#include <iostream>
using namespace std;

// palindrome String : String on reversal reads the same
bool palindrome(int i, string& s) {
    int n = s.size();
    if(i >= n/2) {
        return true;
    }
    if(s[i] != s[n-i-1]) {
        return false;
    }
    return palindrome(i+1,s);
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<palindrome(0,s);
    return 0;
}

// Enter the string : madam
// 1

// Enter the string : madsam
// 0
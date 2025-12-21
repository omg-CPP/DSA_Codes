#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size()-1;
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool recIsPalindrome(string s, int i, int j) {
    if(i > j) {
        return true;
    }
    if(s[i] != s[j]) {
        return false;
    }
    else {
        return recIsPalindrome(s,i+1,j-1);
    }
}

int main()
{
    string str = "racecar";
    cout<<isPalindrome(str)<<endl; // 1
    cout<<recIsPalindrome(str,0,str.size()-1)<<endl; // 1
    return 0;
}
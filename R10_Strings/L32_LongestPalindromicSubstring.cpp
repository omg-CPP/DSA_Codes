// Leetcode : 5
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n^2)
// S.C. = O(1)
string longestPalindrome(string s) {
    // ebbabad
    if(s.size() <= 1) {
        return s;
    }
    string lps = s.substr(0, 1); // Initialize with first character
    for(int i = 0 ; i < s.size() ; i++) {
        // considering odd length
        int lo = i;
        int hi = i;
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
            lo--;
            hi++;
        }
        string palindrome = s.substr(lo+1,hi-lo-1);
        if(palindrome.size() > lps.size()) {
            lps = palindrome;
        }

        // considering even length 
        lo = i;
        hi = i+1;
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
            lo--;
            hi++;
        }
        palindrome = s.substr(lo+1,hi-lo-1);
        if(palindrome.size() > lps.size()) {
            lps = palindrome;
        }
    }
    return lps;
}

int main()
{
    string s = "bababaababadd";
    string str = longestPalindrome(s);
    cout<<str<<endl; // ababaababa
    return 0;
}
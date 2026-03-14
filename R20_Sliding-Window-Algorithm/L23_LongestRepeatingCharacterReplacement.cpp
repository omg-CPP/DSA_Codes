// Leetcode : 424

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Brute force : Think of all possible Substrings
// T.C. = O(n^2)
// S.C. = O(26)
int characterReplacement_Naive(string s, int k) {
    int n = s.size();
    int maxLen = INT_MIN;
    // only uppercase characters
    for(int i = 0 ; i < n ; i++) {
        int hash[26] = {0}; 
        int maxFreq = 0; 
        int changes = 0;
        for(int j = i ; j < n ; j++) {
            hash[s[j]-'A']++;
            maxFreq = max(maxFreq,hash[s[j]-'A']);
            changes = (j-i+1) - maxFreq;
            if(changes <= k) {
                maxLen = max(maxLen,j-i+1);
            }
            else {
                break;
            }
        }
    }
    return maxLen;
}

// Two Pointers + Sliding Window Algorithm
// T.C. = [O(n) + O(n)] * 26 = O(2n) * 26
// S.C. = O(26)
int characterReplacement_Better(string s, int k) {
    int n = s.size();
    int maxLen = INT_MIN;
    int hash[26] = {0}; 
    int maxFreq = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        hash[s[j]-'A']++;
        maxFreq = max(maxFreq,hash[s[j]-'A']);
        // shrink phase
        while((j-i+1) - maxFreq > k) {
            hash[s[i]-'A']--;
            maxFreq = 0;
            // again computing the maxFreq
            for(int i = 0 ; i < 26 ; i++) {
                maxFreq = max(maxFreq,hash[i]);
            }
            i++;
        }
        if((j-i+1) - maxFreq <= k) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return maxLen;
}

// Optimised
// T.C. = O(n)
// S.C. = O(26)
int characterReplacement_Optimal(string s, int k) {
    int n = s.size();
    int maxLen = INT_MIN;
    int hash[26] = {0}; 
    int maxFreq = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        hash[s[j]-'A']++;
        maxFreq = max(maxFreq,hash[s[j]-'A']);
        // shrink phase
        if((j-i+1) - maxFreq > k) {
            hash[s[i]-'A']--;
            maxFreq = 0;
            // again computing the maxFreq
            for(int i = 0 ; i < 26 ; i++) {
                maxFreq = max(maxFreq,hash[i]);
            }
            i++;
        }
        if((j-i+1) - maxFreq <= k) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return maxLen;
}

int main()
{
    string s = "AABABBA";
    int k = 2;
    cout<<characterReplacement_Naive(s,k)<<endl; // 5
    string t = "AAABBCCD";
    cout<<characterReplacement_Better(t,k)<<endl; // 5
    cout<<characterReplacement_Optimal(t,k)<<endl; // 5
    return 0;
}
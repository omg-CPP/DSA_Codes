// Leetcode : 3
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// Naive Approach
// T.C. = O(n^2)
// S.C. = O(256) // hash array
int lengthOfLongestSubstring_Naive(string s) {
    int n = s.size();
    int maxLen = INT_MIN;
    unordered_map<char,int> mp;
    for(int i = 0 ; i < n ; i++) {
        mp.clear(); // every time map mp is cleared
        for(int j = i ; j < n ; j++) {
            // if any element found twice
            if(mp[s[j]] == 1) {
                break;
            }
            maxLen = max(maxLen,j-i+1);
            mp[s[j]] = 1;
        }
    }
    return (maxLen == INT_MIN) ? 0 : maxLen;
}

// Sliding Window + Two Pointers
// T.C. = O(n) + O(1) = O(n)
// S.C. = O(n) 
int lengthOfLongestSubstring_Optimal(string s) {
    int n = s.size();
    int maxLen = INT_MIN;
    unordered_map<char,int> mp; // char,index
    int i = 0;
    int j = 0;
    while(j < n) {
        // If the char is present in the map
        if(mp.find(s[j]) != mp.end()) {
            // check that element is present in the window
            if(mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }
        }
        maxLen = max(maxLen,j-i+1);
        mp[s[j]] = j;
        j++;
    }
    return (maxLen == INT_MIN) ? 0 : maxLen;
}

int main()
{
    string s = "cadbzabcd";
    cout<<lengthOfLongestSubstring_Naive(s)<<endl; // 5
    cout<<lengthOfLongestSubstring_Optimal(s)<<endl; // 5
    return 0;
}
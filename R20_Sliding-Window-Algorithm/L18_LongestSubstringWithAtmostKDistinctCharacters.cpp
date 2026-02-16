// Leetcode : 
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// Brute Force Approach
// T.C. = O(n^2) + O(1) = O(n^2)
// S.C. = O(256) for unordered map
int longestSubstrWithAtmostK_Naive(string& s, int k) {
    int n = s.size();
    int maxLen = INT_MIN;
    unordered_map<char,int> mp;
    for(int i = 0 ; i < n ; i++) {
        mp.clear();
        for(int j = i ; j < n ; j++) {
            mp[s[j]]++;
            if(mp.size() <= k) {
                maxLen = max(maxLen,j-i+1);
            }
            else {
                break;
            }
        }
    }
    return (maxLen == INT_MIN) ? -1 : maxLen;
}

// Sliding Window Algorithm
// T.C. = O(n) + O(n) + O(1) = O(2n)
// S.C. = O(256) for unordered map
int longestSubstrWithAtmostK_Better(string& s, int k) {
    int n = s.size();
    int maxLen = INT_MIN;
    unordered_map<char,int> mp;
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[s[j]]++;
        // shrink phase
        while(mp.size() > k) {
            mp[s[i]]--;
            if(mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size() <= k) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return (maxLen == INT_MIN) ? -1 : maxLen;
}

// Optimised Sliding Window Algorithm
// T.C. = O(n) 
// S.C. = O(256) for unordered map
int longestSubstrWithAtmostK_Optimal(string& s, int k) {
    int n = s.size();
    int maxLen = INT_MIN;
    unordered_map<char,int> mp;
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[s[j]]++;
        // shrink phase
        if(mp.size() > k) {
            mp[s[i]]--;
            if(mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size() <= k) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return (maxLen == INT_MIN) ? -1 : maxLen;
}

int main()
{
    string s = "aaabbccd";
    int k = 2;
    cout<<longestSubstrWithAtmostK_Naive(s,k)<<endl; // 5
    cout<<longestSubstrWithAtmostK_Better(s,k)<<endl; // 5
    cout<<longestSubstrWithAtmostK_Optimal(s,k)<<endl; // 5
    return 0;
}
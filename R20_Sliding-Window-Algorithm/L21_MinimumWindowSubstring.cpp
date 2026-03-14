// Leetcode : 76

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// Brute Force / Better Approach
// T.C. = O(n^2) + O(1)
// S.C. = O(256)
string minWindow_Naive(string s, string t) {
    int n = s.size();
    int m = t.size();
    unordered_map<char,int> mp;
    int minLen = INT_MAX;
    int sIdx = -1;
    for(int i = 0 ; i < n ; i++) {
        mp.clear();
        int count = 0;
        // iterate over t
        for(int j = 0 ; j < m ; j++) {
            mp[t[j]]++;
        }
        // iterate over s
        for(int j = i ; j < n ; j++) {
            if(mp[s[j]] > 0) { // pre-inserted
                count++;
            }
            mp[s[j]]--;
            if(count == m) {
                if(j-i+1 < minLen) {
                    minLen = j-i+1;
                    sIdx = i;
                    break;
                }
            }
        }
    }
    return (sIdx == -1) ? "" : s.substr(sIdx,minLen);
}

// Sliding Window Approach
// T.C. = O(n) + O(n) + O(1) = O(2n)
// S.C. = O(256)
string minWindow_Optimal(string s, string t) {
    int n = s.size();
    int m = t.size();
    unordered_map<char,int> mp;
    int minLen = INT_MAX;
    int sIdx = -1;
    int count = 0;
    // iterate over t  :  pre-insertion
    mp.clear();
    for(int i = 0 ; i < m ; i++) {
        mp[t[i]]++;
    }
    int i = 0; int j = 0;
    while(j < n) {
        if(mp[s[j]] > 0) {
            count++;
        }
        mp[s[j]]--;
        // shrink phase
        while(count == m) {
            if(j-i+1 < minLen) {
                minLen = j-i+1;
                sIdx = i;
            }
            // shrinking
            mp[s[i]]++;
            if(mp[s[i]] > 0) { // re-inserted into the map
                count--;
            }
            i++;
        }
        j++;
    }
    return (sIdx == -1) ? "" : s.substr(sIdx,minLen);
}

int main()
{
    string s = "ddaaabbca";
    string t = "abc";
    string str = minWindow_Naive(s,t);
    cout<<str<<endl; // bca
    string st = minWindow_Optimal(s,t);
    cout<<st<<endl; // bca
    cout<<s.substr(6,3)<<endl; // bca
    return 0;
}


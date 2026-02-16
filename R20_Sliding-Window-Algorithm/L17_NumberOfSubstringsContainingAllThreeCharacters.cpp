// Leetcode : 1358

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Brute Force Soln
// T.C. = O(n^2)
// S.C. = O(3) : a,b,c : in map
int numberOfSubstrings_Naive(string s) {
    int n = s.size();
    int count = 0;
    unordered_map<char,int> mp;
    for(int i = 0 ; i < n ; i++) {
        mp.clear();
        for(int j = i ; j < n ; j++) {
            mp[s[j]] = 1;
            if(mp.size() == 3) {
                count++;
            }
        }
    }
    return count;
}


int numberOfSubstrings_Better(string s) {
    int n = s.size();
    int count = 0;
    unordered_map<char,int> mp;
    for(int i = 0 ; i < n ; i++) {
        mp.clear();
        for(int j = i ; j < n ; j++) {
            mp[s[j]] = 1;
            if(mp.size() == 3) {
                count += n-j;
                break;
            }
        }
    }
    return count;
}

// Sliding Window + Two pointers
// With every character, there is a substring that ends : Intuition
// T.C. = O(n)
// S.C. = O(3) = O(1) : hash array
int numberOfSubstrings_Optimal(string s) {
    int n = s.size();
    int count = 0;
    int lastScene[3] = {-1,-1,-1};
    for(int i = 0 ; i < n ; i++) {
        lastScene[s[i]-'a'] = i;
        if(lastScene[0] != -1 && lastScene[1] != -1 && lastScene[2] != -1) {
            count = count + (1 + min(lastScene[0],min(lastScene[1],lastScene[2])));
        }
    }
    return count;
}

int main()
{
    string s = "bbacba";
    cout<<numberOfSubstrings_Naive(s)<<endl; // 9
    cout<<numberOfSubstrings_Better(s)<<endl; // 9
    cout<<numberOfSubstrings_Optimal(s)<<endl; // 9
    return 0;
}
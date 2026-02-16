// Leetcode : 904
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Finding the max length subarray with at most 2 types of numbers

// Brute Force
// T.C. = O(n^2)
// S.C. = O(3) = O(1) = constant : set space
int totalFruit_Naive(vector<int>& fruits) {
    int n = fruits.size();
    int maxLen = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        unordered_set<int> st;
        for(int j = i ; j < n ; j++) {
            st.insert(fruits[j]);
            if(st.size() <= 2) {
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
// S.C. = O(3) = O(1) = constant : map space
int totalFruit_Better(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int,int> mp; // map of num,freq : O(1) 
    int maxLen = INT_MIN;
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[fruits[j]]++;
        // Shrink phase
        if(mp.size() > 2) {
            while(mp.size() > 2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
        }
        // update phase
        if(mp.size() <= 2) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return (maxLen == INT_MIN) ? -1 : maxLen;
}

// Optimised Sliding Window Algorithm
// T.C. = O(n) 
// S.C. = O(3) = O(1) = constant
// Intuition : Not allowing the length less than 5 in this case till we get a new maxLen and than update it
int totalFruit_Optimal(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int,int> mp; // map of num,freq : O(1) 
    int maxLen = INT_MIN;
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[fruits[j]]++;
        // Shrink phase
        if(mp.size() > 2) {
            mp[fruits[i]]--;
            if(mp[fruits[i]] == 0) {
                mp.erase(fruits[i]);
            }
            i++;
        }
        // update phase
        if(mp.size() <= 2) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return (maxLen == INT_MIN) ? -1 : maxLen;
}

int main()
{
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<totalFruit_Naive(fruits)<<endl; // 5
    cout<<totalFruit_Better(fruits)<<endl; // 5
    cout<<totalFruit_Optimal(fruits)<<endl; // 5
    return 0;
}
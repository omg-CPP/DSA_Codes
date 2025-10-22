// Leetcode : 219

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// T.C. = O(1) + O(n) = O(n)
// S.C. = O(n)
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> mp; // {ele,index}
    for(int i = 0 ; i < n ; i++) {
        // element exsist in the map
        if(mp.find(nums[i]) != mp.end() && abs(i - mp[nums[i]]) <= k) {
            return true;
        }
        else {
            mp[nums[i]] = i;
        }
    }
    return false;
}

// Sliding Window Approach
// T.C. = O(n)
// S.C. = O(n)
bool containsNearbyDuplicateOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_set<int> st; 
    int i = 0;
    int j = 0;
    while(j < n) {
        // shrink phase
        if(abs(i-j) > k) {
            st.erase(nums[i]);
            i++;
        }
        // if element present in the set
        if(st.find(nums[j]) != st.end()) {
            return true;
        }
        else {
            st.insert(nums[j]);
        }
        j++;
    }
    return false;
}

int main()
{
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    cout<<containsNearbyDuplicate(nums,k)<<endl; // false
    cout<<containsNearbyDuplicateOptimal(nums,k)<<endl; // false
    return 0;
}
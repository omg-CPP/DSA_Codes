// Leetcode : 217

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Brute Force
// T.C. = O(n^2) 
// S.C. = O(1)
bool containsDuplicateNaive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i != j && nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

// Using Sorting
// T.C. = O(n) + O(nlogn) = O(nlogn)
// S.C. = O(1)
bool containsDuplicateBetter(vector<int>& nums) {
    int n = nums.size();
    sort(begin(nums),end(nums));
    for(int i = 0 ; i < n-1 ; i++) {
        if(nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}

// Using HashMaps
// T.C. = O(n) + O(n) + O(1) = O(n)
// S.C. = O(n)
bool containsDuplicateOptimal(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mp; // {ele,freq}
    for(int i = 0 ; i < n ; i++) {
        mp[nums[i]]++;
    }
    for(int i = 0 ; i < n ; i++) {
        if(mp[nums[i]] >= 2) {
            return true;
        }
    }
    return false;
}

// Using HashSets
// T.C. = O(n)
// S.C. = O(n)
bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> st;
    for(int i = 0 ; i < n ; i++) {
        // If element exsist in the set
        if(st.find(nums[i]) != st.end()) {
            return true;
        }
        else {
            st.insert(nums[i]);
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    cout<<containsDuplicateNaive(nums)<<endl; // 1
    cout<<containsDuplicateBetter(nums)<<endl; // 1
    cout<<containsDuplicateOptimal(nums)<<endl; // 1
    cout<<containsDuplicate(nums)<<endl; // 1
    return 0;
}
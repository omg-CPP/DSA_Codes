// Leetcode : 220
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n*k)
// S.C. = O(n)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    int k = indexDiff;
    int t = valueDiff;
    unordered_set<int> st;
    for(int i = 0 ; i < n ; i++) {
        st.insert(nums[i]);
    }
    // if array has all unique elements and valueDiff == 0
    // which means abs(nums[i]-nums[j]) <= 0 => not possible
    if(t == 0 && st.size() == n) {
        return false;
    }
    for(int i = 0 ; i < n ; i++) { // O(n)
        for(int j = i+1 ; j < i+1+k ; j++) { // O(k)
            if(j >= n) {
                break;
            }
            if(abs(nums[i]-nums[j]) <= t) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    int indexDiff = 3;
    int valueDiff = 0;
    cout<<containsNearbyAlmostDuplicate(nums,indexDiff,valueDiff)<<endl; // 1
    return 0;
}
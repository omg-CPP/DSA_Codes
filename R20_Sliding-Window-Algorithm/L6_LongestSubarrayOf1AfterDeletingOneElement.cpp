// Leetcode : 1493
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.


// Brute Force : T.C. = O(n^2)

int findMax(vector<int>& nums, int skip_idx) {
    int n = nums.size();
    int currLen = 0;
    int maxLen = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        if(i == skip_idx) {
            continue;
        }
        if(nums[i] == 1) {
            currLen++;
            maxLen = max(maxLen,currLen);
        }
        else { // nums[i] == 0
            currLen = 0;
        }
    }
    return maxLen;
}

int longestSubarray_BruteForce(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    int countZero = 0;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == 0) {
            countZero++;
            result = max(result,findMax(nums,i));
        }
    }
    if(countZero == 0) {
        return n-1;
    }
    return result;
}

// Standard Two Pointers + Sliding Window Algorithm
// T.C. = O(n) + O(n) = O(n)
int longestSubarray_Better(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int zeroCount = 0;
    int maxLen = INT_MIN;
    while(j < n) {
        if(nums[j] == 0) {
            zeroCount++;
        }
        while(zeroCount > 1) {
            if(nums[i] == 0) {
                zeroCount--;
            }
            i++;
        }
        maxLen = max(maxLen,j-i);
    }
    return maxLen;
}

// T.C. = O(n) -> Optimised Sliding Window Algorithm
// Every Element is traversed only once
int longestSubarray_Optimal(vector<int>& nums) {
    int n = nums.size();
    int lastZeroIdx = -1;
    int maxLen = INT_MIN;
    int i = 0;
    int j = 0;
    while(j < n) {
        if(nums[j] == 0) {
            i = lastZeroIdx + 1;
            lastZeroIdx = j;
        }
        maxLen = max(maxLen,j-i);
        j++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    int ans = longestSubarray_BruteForce(nums);
    cout<<ans<<endl;
    return 0;
}
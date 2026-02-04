// Leetcode : 1004
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Brute Force : Longest Subarray with atmost k zeros
// T.C. = O(n^2)
// S.C. = O(1)

int longestOnes_BruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int zeros = 0;
    int len = 0;
    int maxLen = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        zeros = 0;
        for(int j = i ; j < n ; j++) {
            if(nums[j] == 0) {
                zeros++;
            }
            if(zeros <= k) {
                len = j-i+1;
                maxLen = max(maxLen,len);
            }
            else {
                break;
            }
        }
    }
    return maxLen;
}

// Two Pointers and Sliding Window Algorithm
// T.C. = O(n) for j movement
// i in total moves n times
// T.C. = O(n) + O(n) = O(n)
int longestOnes_Better(vector<int>& nums, int k) {
    int n = nums.size();
    int len = 0;
    int maxLen = INT_MIN;
    int zeros = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        if(nums[j] == 0) {
            zeros++;
        }
        while(zeros > k) {
            if(nums[i] == 0) {
                zeros--;
            }
            i++;
        }
        if(zeros <= k) {
            len = j-i+1;
            maxLen = max(maxLen,len);
        }
        j++;
    }
    return maxLen;
}

// Sliding Window and Two Pointers : Eliminating the inner while loop also to improve the T.C.
// T.C. = O(n)
// S.C. = O(1)
int longestOnes_Optimal(vector<int>& nums, int k) {
    int n = nums.size();
    int len = 0;
    int maxLen = INT_MIN;
    int zeros = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        if(nums[j] == 0) {
            zeros++;
        }
        if(zeros > k) {
            if(nums[i] == 0) {
                zeros--;
            }
            i++;
        }
        if(zeros <= k) {
            len = j-i+1;
            maxLen = max(maxLen,len);
        }
        j++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int ans = longestOnes_Optimal(nums,k);
    cout<<ans<<endl; // 6
    return 0;
}
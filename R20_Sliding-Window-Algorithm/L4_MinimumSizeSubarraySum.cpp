// Leetcode : 209
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// we need to find the size of the window in this case

// Total Operations <= 2n
// T.C. = O(n)
// S.C. = O(1)
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int minLen = INT_MAX;
    int len = 0;
    int sum = 0;
    while(j < n) {
        sum += nums[j];
        while(i <= j && sum >= target) {
            len = j-i+1;
            minLen = min(minLen,len);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(minLen == INT_MAX) {
        return 0;
    }
    return minLen;
}

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int minLen = minSubArrayLen(target,nums);
    cout<<minLen<<endl; // 2
    return 0;
}

// to understand the condition i <= j
// check a dry run for nums = [2,3,1,2,4,8] => o/p = 1 which is subarray [8]
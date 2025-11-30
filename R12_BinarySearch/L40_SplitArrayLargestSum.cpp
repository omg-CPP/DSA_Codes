// Leetcode : 410

// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized meaning the maximum subarray sum is minimised.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// c1 : [10] [20 30 40] :: 10 + 90 :: max = 90
// c2 : [10 20] [30 40] :: 30 + 70 :: max = 70
// c3 : [10 20 30] [40] :: 60 + 40 :: max = 60

// min(max)

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int countSubarrays(vector<int>& nums, int maxSum) {
    int n = nums.size();
    int subarrays = 1;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        if(sum + nums[i] <= maxSum) {
            sum += nums[i];
        }
        else {
            subarrays++;
            sum = nums[i];
        }
    }
    return subarrays;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int lo = *max_element(nums.begin(),nums.end());
    int hi = accumulate(nums.begin(),nums.end(),0);
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(countSubarrays(nums,mid) > k) {
            lo = mid + 1;
        }
        else { // countSubarrays(arr,mid) <= k
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    return 0;
}
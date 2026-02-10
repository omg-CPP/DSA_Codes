// Leetcode : 713
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

// 1 <= nums[i] <= 1000

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // k -> target
    int n = nums.size();
    // nums = {10,5,2,6}
    if(k <= 1) {
        return 0;
    }
    int i = 0;
    int j = 0;
    int count = 0;
    int product = 1;
    while(j < n) {
        product = product * nums[j];
        while(i <= j && product >= k) {
            count = count + (j-i);
            product = product / nums[i];
            i++;
        }
        j++;
    }
    // for left out subarray cases 
    while(i < n) {
        count = count + (j-i);
        product = product / nums[i];
        i++;
    }
    return count;
}

int main()
{
    vector<int> nums = {10,5,2,6};
    int k = 100;
    int ans = numSubarrayProductLessThanK(nums,k);
    cout<<ans<<endl; // 8
    return 0;
}
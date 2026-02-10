// Leetcode : 1248

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    if(k < 0) {
        return 0;
    }
    int n = nums.size();
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += (nums[j] % 2);
        // window shrink
        while(sum > k) {
            sum -= (nums[i] % 2);
            i++;
        }
        count += (j-i+1);
        j++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout<<numberOfSubarrays(nums,k)-
    numberOfSubarrays(nums,k-1)<<endl; // 2
    return 0;
}
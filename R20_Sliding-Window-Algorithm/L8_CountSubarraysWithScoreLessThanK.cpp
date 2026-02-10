// Leetcode : 2302

// The score of an array is defined as the product of its sum and its length.

// For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

// A subarray is a contiguous sequence of elements within an array.

// T.C. = O(n) + O(n) = O(2n) = O(n)
// S.C. = O(1)

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

long long countSubarrays(vector<int>& nums, long long k) {
    long long count = 0;
    long long sum = 0;
    int n = nums.size();
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += nums[j];
        // score of a subarray = sum * (j-i+1)
        while(i <= j && sum*(j-i+1) >= k) { // window shrink case
            sum -= nums[i];
            i++;
        }
        count += (j-i+1); 
        j++;
        // suppose array is [a,b,c,d,e,f]
        // i = 1 && j = 4
        // if [b,c,d,e] is a valid subarray
        // if (b+c+d+e)*4 < k  => [b,c,d,e]
        // then (c+d+e)*3 < k  => [c,d,e]
        // then (d+e)*2 < k    => [d,e]
        // then (e)*1 < k      => [e]
        // So total subarrays obtained = (j-i+1) = 4 = length of subarray
    }
    return count;
}

int main()
{
    vector<int> nums = {2,1,4,3,5};
    long long k = 10;
    long long count = countSubarrays(nums,k);
    cout<<count<<endl; // 6
    return 0;
}
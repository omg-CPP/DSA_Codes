#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// Longest Subarray with sum <= K
// OR
// Longest Subarray having sum of elements atmost K

// T.C. = O(n^2)
// S.C. = O(1)
int atmostSum_Naive(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int sum = 0;
        for(int j = i ; j < n ; j++) {
            sum += nums[j];
            if(sum <= k) {
                maxLen = max(maxLen,j-i+1);
            }
            else { // sum > k
                break;
            }
        }
    }
    return maxLen;
}

// T.C. = O(n) + O(n) = O(n)
// S.C. = O(1)
int atmostSum_Optimal(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = INT_MIN;
    int sum = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += nums[j];
        while(sum > k) {
            sum -= nums[i];
            i++;
        }
        if(sum <= k) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return maxLen;
}

// T.C. = O(n)
// S.C. = O(1)
int LonestSubarrayWithSumLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = INT_MIN;
    int sum = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += nums[j];
        // Optimised Code
        if(sum > k) {
            sum -= nums[i];
            i++;
        }
        if(sum <= k) {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1,2,1,0,1,1,0};
    int k1 = 4;
    cout<<atmostSum_Optimal(nums,k1)<<endl; // 5
    cout<<LonestSubarrayWithSumLessThanK(nums,k1)<<endl; // 5
    vector<int> arr = {8,2,4,0,1,1,0};
    int k2 = 9;
    cout<<atmostSum_Optimal(arr,k2)<<endl; // 6
    return 0;
}
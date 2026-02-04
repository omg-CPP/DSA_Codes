#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// T.C. = O((n-k+1)*k) = O(kn)
// S.C. = O(1)
// k is not a constant
int maximumSumSubarrayOfSizeK_BruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int idx = -1;
    for(int i = 0 ; i <= n-k ; i++) { // n-k+1 times
        int sum = 0;
        for(int j = i ; j < i+k ; j++) { // k times
            sum = sum + nums[j];
            if(maxSum < sum) {
                maxSum = sum;
                idx = i;
            }
        }
    }
    cout<<maxSum<<" "<<idx<<endl; // 21 4
    return maxSum;
}

// Sliding Window Algorithm
// T.C. = O(n)
// S.C. = O(1)
int maximumSumSubarrayOfSizeK_Optimal(vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int idx = 0;
    int prevSum = 0;
    // to find the previousSum (first window sum)
    for(int i = 0 ; i < k ; i++) { // k times
        prevSum = prevSum + nums[i];
    }
    maxSum = prevSum;
    // Sliding Window Algorithm
    int i = 1;
    int j = k;
    while(j < n) { // n-k times
        int currentSum = prevSum + nums[j] - nums[i-1];
        if(maxSum < currentSum) {
            maxSum = currentSum;
            idx = i;
        }
        prevSum = currentSum;
        i++;
        j++;
    }
    cout<<maxSum<<" "<<idx<<endl;
    return maxSum;
}

int main()
{
    vector<int> nums = {7,1,2,5,8,4,9,3,6};
    int k = 3;
    int sum = maximumSumSubarrayOfSizeK_BruteForce(nums,k);
    cout<<sum<<endl; // 21

    int windowSize = 4;
    int ans = maximumSumSubarrayOfSizeK_Optimal(nums,windowSize); // 26 3
    cout<<ans<<endl; // 26
    return 0;
}
// Leetcode : 3381

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force : TLE
// T.C. = O(N^2)
// S.C. = O(N)
long long maxSubarraySum_Naive(vector<int>& nums, int k) {
    int n = nums.size();
    // Create prefix sum array
    vector<long long> prefixSum(n);
    prefixSum[0] = nums[0];
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    // after start = k-1 , repetition starts refer example
    // [1,-2,3,4,-5], k = 2
    long long maxSum = LLONG_MIN;
    for(int i = 0 ; i < n ; i++) {
        long long currSubSum = 0;
        for(int j = i + k - 1 ; j < n ; j += k) {
            long long currSubSum = prefixSum[j] - ((i > 0) ? prefixSum[i-1] : 0);
            maxSum = max(maxSum, currSubSum);
        }
    }
    return maxSum;
}

// Optimal Approach : Kadane's Algorithm
// T.C. = O(N)
// S.C. = O(N)
long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Create prefix sum array
    vector<long long> prefixSum(n);
    prefixSum[0] = nums[0];
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    long long maxSum = LLONG_MIN;
    
    // after start = k-1 , repetition starts refer example
    // [1,-2,3,4,-5], k = 2
    for(int start = 0 ; start < k ; start++) {
        long long currSum = 0;
        int i = start;
        while(i < n && i + k - 1 < n) {
            int j = i + k - 1;
            long long subSum = prefixSum[j] - ((i > 0) ? prefixSum[i-1] : 0);
            currSum = max(subSum, currSum + subSum);
            maxSum = max(maxSum, currSum);
            i += k;
        }
    }
    return maxSum;
}

int main()
{
    return 0;
}
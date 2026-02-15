#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Subarray Sum Equals K : Leetcode 560

int subarraySumEqualsK_Naive(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        int sum = 0;
        for(int j = i ; j < n ; j++) {
            sum += nums[j];
            if(sum == k) {
                count++;
            }
        }
    }
    return count;
}

// Prefix Sum + Hashing + Subarray Sum Equals K
int subarraySumEqualsK(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    unordered_map<int,int> mp; // prefixSum and frequency
    vector<int> prefixSum(n,0);
    prefixSum[0] = nums[0];
    // creating the prefixSum array
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    // checking for subarray sum equals k
    // moving the right boundary and calculating the left boundary with the help of k
    for(int j = 0 ; j < n ; j++) {
        // 1st case
        if(prefixSum[j] == k) {
            count++;
        }
        // 2nd case
        // k = prefixSum[j] - prefixSum[i-1]
        // prefixSum[i-1] = prefixSum[j] - k
        // val = prefixSum[i-1]
        int val = prefixSum[j] - k;
        // checking if the value exist in the map
        if(mp.find(val) != mp.end()) {
            count = count + mp[val];
        }
        // checking if the value does not exist in the map
        // The check if(mp.find(prefixSum[j]) == mp.end()) ensures that we initialize the count for this prefix sum to 0 before incrementing it.

        // This is necessary because mp[prefixSum[j]]++ assumes the key already exists in the map. If the key doesn't exist, mp[prefixSum[j]] would default-initialize to 0 (due to how unordered_map works in C++), and then increment it to 1.
        if(mp.find(prefixSum[j]) == mp.end()) {
            mp[prefixSum[j]] = 0;
        }
        mp[prefixSum[j]]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    cout<<subarraySumEqualsK_Naive(nums,k)<<endl; // 8
    cout<<subarraySumEqualsK(nums,k)<<endl; // 8
    return 0;
}
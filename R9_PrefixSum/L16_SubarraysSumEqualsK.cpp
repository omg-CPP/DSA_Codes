// Leetcode : 560

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// nums = [1 2 3] , k = 3
// subarrays = [1], [1 2], [1 2 3], [2], [2 3], [3]
// subarrays with sum equals 3  = [1 2], [3]
// count = 2

// running sum
// T.C. = O(n^2)
// S.C. = O(1)
int subarraySum_NAIVE(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        int sum = 0;
        for(int j = i ; j < n ; j++) {
            sum = sum + nums[j];
            if(sum == k) {
                count++;
            }
        }
    }
    return count;
}

// T.C. is mostly more important than S.C.
// Optimal Approach : Prefix Sum + Hashing (unordered_map -> O(1))
// T.C. = O(n) + O(n) = O(n) 
// unordered_map operations take O(1) time
// S.C. = O(n) + O(n) = O(n)
// prefixSum array space + unordered_map space
int subarraySum(vector<int>& nums, int k) {
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
        if(mp.find(prefixSum[j]) == mp.end()) {
            mp[prefixSum[j]] = 0;
        }
        mp[prefixSum[j]]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {9,4,0,20,3,10,5};
    int k = 33;
    int ans = subarraySum(nums,k);
    cout<<ans<<endl; // 3
    return 0;
}

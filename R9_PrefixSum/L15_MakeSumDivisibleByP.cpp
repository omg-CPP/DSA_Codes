// Leetcode : 1590

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// brute force : TLE
// T.C. = O(N^2)
// S.C. = O(1)
int minSubarray_NAIVE(vector<int>& nums, int p) {
    int n = nums.size();
    long totalSum = 0;
    for(int& num : nums) {
        totalSum += num;
    }
    int rem = totalSum % p;
    if(rem == 0) {
        return 0;
    }
    int minLength = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        long subarraySum = 0;
        for(int j = i ; j < n ; j++) {
            subarraySum += nums[j];
            // Check if removing current subarray makes remaining sum divisible by p
            // AND we're not removing the entire array (j-i+1 != n)
            if(((rem - subarraySum % p) % p == 0) && j-i+1 != n) {
                minLength = min(minLength,j-i+1);
            }
        }
    }
    return minLength == INT_MAX ? -1 : minLength;
}


// (a + b) % p = (a % p + b % p) % p
// T.C. = O(N)
// S.C. = O(N)
int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    int totalSum = 0;
    for(int& num : nums) {
        totalSum = (totalSum + num) % p;
    }
    int target = totalSum % p;
    if(target == 0) {
        return 0;
    }
    int minLength = n;
    unordered_map<int,int> mp;  // {sum % p, idx}

    int curr = 0;
    mp[0] = -1;

    for(int j = 0 ; j < n ; j++) {
        curr = (curr + nums[j]) % p;
        int remain = (curr - target + p) % p;
        if(mp.find(remain) != mp.end()) {
            minLength = min(minLength, j - mp[remain]);
        }
        mp[curr] = j;
    }
    return minLength == n ? -1 : minLength;
}


int main()
{
    return 0;
}
// Leetcode : 525
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Length of Longest Subarray with Target Sum Equals 0
// 0 -> -1
// 1 -> 1
// T.C. = O(n) + O(n) + O(1) = O(2n) = O(n)
// S.C. = O(n) + O(n) = O(2n) = O(n)
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mp; // prefixSum : index
    mp[0] = -1;
    int maxLen = INT_MIN;
    vector<int> prefixSum(n,0);
    prefixSum[0] = (nums[0] == 0) ? -1 : 1;
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] += prefixSum[i-1];
        prefixSum[i] += (nums[i] == 0) ? -1 : 1;
    }
    for(int i = 0 ; i < n ; i++) {
        if(mp.find(prefixSum[i]) != mp.end()) {
            maxLen = max(maxLen,i-mp[prefixSum[i]]);
        }
        else {
            mp[prefixSum[i]] = i;
        }
    }
    return maxLen == INT_MIN ? 0 : maxLen;
}

int main()
{
    vector<int> nums = {0,0,1,0,0,0,1,1};
    int len = findMaxLength(nums);
    cout<<len<<endl; // 6
    return 0;
}
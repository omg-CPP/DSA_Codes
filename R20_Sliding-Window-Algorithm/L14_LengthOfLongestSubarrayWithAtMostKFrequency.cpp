// Leetcode : 2958
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// T.C. = O(n) + O(n) = O(2n)
// S.C. = O(n)
int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = INT_MIN;
    unordered_map<int,int> mp;  // nums[i],freq
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[nums[j]]++;
        // shrink phase
        while(mp[nums[j]] > k) {
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }
        maxLen = max(maxLen,j-i+1);
        j++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;
    cout<<maxSubarrayLength(nums,k)<<endl; // 6
    return 0;
}
// Leetcode : 523
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// PrefixSum + Hashing 
// T.C. = O(n) + O(n) + O(1) = O(2n) = O(n)
// S.C. = O(n) + O(n) = O(2n) = O(n)
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n,0);
    prefixSum[0] = nums[0];
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    unordered_map<int,int> mp;
    mp[0] = -1; // inorder to check default case : {23,2,6,4,7} & k = 7
    for(int i = 0 ; i < n ; i++) {
        if(mp.find(prefixSum[i] % k) != mp.end()) {
            if(i-mp[prefixSum[i] % k] >= 2) {
                return true;
            }
        }
        else {
            mp[prefixSum[i] % k] = i;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    cout<<checkSubarraySum(nums,k)<<endl; // 1
    return 0;
}
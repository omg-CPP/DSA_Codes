// Leetcode : 992

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force 
// T.C. = O(n^2)
// S.C. = O(n)
int subarraysWithKDistinct_Naive(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        unordered_map<int,int> mp;
        for(int j = i ; j < n ; j++) {
            mp[nums[j]]++;
            if(mp.size() == k) {
                count++;
            }
            else if(mp.size() > k) {
                break;
            }
        }
    }
    return count;
}

// No of Subarrays where Distinct Integers <= k
// Sliding Window Approach + Two pointers
// T.C. = O(n) + O(n) = O(2n) 
// S.C. = O(n) : map
// Overall T.C. = 2*O(n)

// No of Subarrays where Distinct Integers <= k
int helper(vector<int>& nums, int k) {
    if(k <= 0) {
        return 0;
    }
    int n = nums.size();
    int count = 0;
    unordered_map<int,int> mp;
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[nums[j]]++;
        // shrink phase
        while(i <= j && mp.size() > k) {
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }
        // update phase
        if(mp.size() <= k) {
            count += (j-i+1);
        }
        j++;
    }
    return count;
}

int subarraysWithKDistinct_Optimal(vector<int>& nums, int k) {
    int n = nums.size();
    // [No of Subarrays where Distinct Integers <= k] - [No of Subarrays where Distinct Integers <= k-1]
    return helper(nums,k) - helper(nums,k-1);
}

int main()
{
    vector<int> nums = {2,1,1,1,3,4,3,2};
    int k = 3;
    cout<<subarraysWithKDistinct_Naive(nums,k)<<endl; // 9
    cout<<subarraysWithKDistinct_Optimal(nums,k)<<endl; // 9
    return 0;
}
// Leetcode : 442

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// T.C. = O(n)
// S.C. = O(n)
vector<int> findDuplicatesNaive(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i = 0 ; i < n ; i++) {
        mp[nums[i]]++;
    }
    for(auto it : mp) {
        if(it.second == 2) {
            ans.push_back(it.first);
        }
    }
    return ans;
}

// 1 <= nums[i] <= n
// Use Numbers as Index
// if n = 8 :: no's in array :: [1,8]
// T.C. = O(n)
// S.C. = O(1)
vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0 ; i < n ; i++) {
        int num = abs(nums[i]);
        int idx = num-1;
        if(nums[idx] < 0) {
            ans.push_back(num);
        }
        else {
            nums[idx] *= -1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,1,2,2,3,4,5,5,6,7,7,8};
    vector<int> res = findDuplicatesNaive(nums);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    // 7 5 1 2 
    cout<<endl;
    vector<int> ans = findDuplicates(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 2 5 7 
    cout<<endl;
    return 0;
}
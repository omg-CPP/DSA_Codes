#include <iostream>
#include <vector>
using namespace std;
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int freq[]) {
    int n = nums.size();
    // base case
    if(v.size() == n) {
        ans.push_back(v);
        return;
    }
    for(int i = 0 ; i < n ; i++) {
        if(!freq[i]) { // if 1 or 2 or 3 is not count or taken
            v.push_back(nums[i]);
            freq[i] = 1;
            helper(nums,v,ans,freq);
            freq[i] = 0;
            v.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> v;
    int freq[n];
    for(int i = 0 ; i < n ; i++) {
        freq[i] = 0;
    }
    helper(nums,v,ans,freq);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        for(int j = 0 ; j < ans[i].size() ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 
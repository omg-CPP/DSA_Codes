#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int>& nums, vector<int> v, vector<vector<int>>& ans, int idx, bool flag) {
    int n = nums.size();
    // base case
    if(idx == n) {
        ans.push_back(v);
        return;
    }
    int x = nums[idx];
    if(idx == n-1) {
        if(flag == true) {
            // left call
            helper(nums,v,ans,idx+1,true);
        }
        v.push_back(nums[idx]);
        helper(nums,v,ans,idx+1,true);
        return;
    }
    int y = nums[idx+1];
    if(x == y) { // duplicates
        if(flag == true) {
            // left call
            helper(nums,v,ans,idx+1,true);
        }
        v.push_back(nums[idx]);
        helper(nums,v,ans,idx+1,false);
        return;
    }
    else { // no duplicates
        if(flag == true) {
            // left call
            helper(nums,v,ans,idx+1,true);
        }
        v.push_back(nums[idx]);
        helper(nums,v,ans,idx+1,true);
        return;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> subsets;
    vector<int> v;
    bool flag = true;
    helper(nums,v,subsets,0,flag);
    return subsets;
}

int main()
{
    vector<int> nums = {1,2,2};
    sort(nums.begin(),nums.end());
    vector<vector<int>> result = subsetsWithDup(nums);
    for(int i = 0 ; i < result.size() ; i++) {
        for(int j = 0 ; j < result[i].size() ; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// {}
// 2 
// 2 2 
// 1 
// 1 2 
// 1 2 2 


// vector<int> nums = {4,4,4,1,4};
// {}
// 4 
// 4 4 
// 4 4 4 
// 4 4 4 4 
// 1 
// 1 4 
// 1 4 4 
// 1 4 4 4 
// 1 4 4 4 4 

// [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
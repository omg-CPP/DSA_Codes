#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// subsets : {1,2,3}
// {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}}

// Recusrive Solution : Using v as a vector pass by value : Deep copy
void helper(vector<int>& nums, vector<int> v, vector<vector<int>>& ans, int idx) {
    int n = nums.size();
    if(idx == n) {
        ans.push_back(v);
        return;
    }
    helper(nums,v,ans,idx+1);
    v.push_back(nums[idx]);
    helper(nums,v,ans,idx+1);
}


vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> v;
    vector<vector<int>> ans;
    helper(nums,v,ans,0);
    return ans;
}

void printSubset(int arr[], int n, int idx, vector<int> ans) {
    if(idx == n) {
        for(int i = 0 ; i < ans.size() ; i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubset(arr,n,idx+1,ans);
    ans.push_back(arr[idx]);
    printSubset(arr,n,idx+1,ans);
}

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    printSubset(arr,n,0,v);
    // -> empty subset
    // 3 
    // 2 
    // 2 3 
    // 1 
    // 1 3 
    // 1 2 
    // 1 2 3 


    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    for(int i = 0 ; i < result.size() ; i++) {
        for(int j = 0 ; j < result[i].size() ; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    // -> empty set
    // 3 
    // 2 
    // 2 3 
    // 1 
    // 1 3 
    // 1 2 
    // 1 2 3 
    cout<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int idx) {

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> v;
    bool flag = true;
    helper(nums,v,ans,0);
    return ans;
}

int main()
{
    vector<int> nums = {1,1,2};
    sort(nums.begin(), nums.end());
    vector<int> freq(20,0);
    for(int i = 0 ; i < nums.size() ; i++) {
        
    }
    vector<vector<int>> res = permuteUnique(nums);
    for(int i = 0 ; i < res.size() ; i++) {
        for(int j = 0 ; j < res[i].size() ; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
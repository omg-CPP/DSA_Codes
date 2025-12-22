#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// T.C. = 

void helper(int idx, vector<int>& candidates, vector<int>& v, vector<vector<int>>& ans, int target) {
    int n = candidates.size();
    // base case
    if(target == 0) {
        ans.push_back(v);
        return;
    }
    // if(target < 0) {
    //     return;
    // }
    for(int i = idx ; i < n ; i++) {
        if((i > idx) && (candidates[i] == candidates[i-1])) {
            continue;
        }
        if(candidates[i] > target) {
            break;
        }
        v.push_back(candidates[i]);
        helper(i+1,candidates,v,ans,target-candidates[i]);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // lexographical order
    sort(candidates.begin(),candidates.end());
    vector<int> v;
    vector<vector<int>> ans;
    helper(0,candidates,v,ans,target);
    return ans;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates,target);
    cout<<"[";
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<"[ ";
        for(int j = 0 ; j < res[i].size() ; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
    // [[ 1 1 6 ][ 1 2 5 ][ 1 7 ][ 2 6 ]]
    return 0;
}
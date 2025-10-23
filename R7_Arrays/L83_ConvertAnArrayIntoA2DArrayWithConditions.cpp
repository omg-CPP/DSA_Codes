// Leetcode : 2610
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// T.C. = O(n)
// S.C. = O(n)
vector<vector<int>> findMatrix(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mp; // {ele,freq}
    vector<vector<int>> ans;

    for(int i = 0 ; i < n ; i++) {
        int freq;
        // if element is present in the map
        if(mp.find(nums[i]) != mp.end()) {
            freq = mp[nums[i]];
        }
        else {
            freq = 0;
        }
        if(freq == ans.size()) { // freq == noOfRows
            ans.push_back({}); // adding one new row
        }
        ans[freq].push_back(nums[i]);
        mp[nums[i]]++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,4,1,2,3,1};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 1 3 4 1 2 3 1 
    cout<<endl;
    vector<vector<int>> ans = findMatrix(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        for(int j = 0 ; j < ans[i].size() ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1 3 4 2 
// 1 3 
// 1 
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> triplet(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i = 0 ; i < n ; i++) {
        // skip the duplicates
        if(i > 0 && arr[i] == arr[i-1]) {
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum == 0) {
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates
                while(j < k && arr[j] == arr[j-1]) {
                    j++;
                }
                // skip the duplicates
                while(j < k && arr[k] == arr[k+1]) {
                    k--;
                }
            }
            else if(sum < 0) {
                j++;
            }
            else { // sum > 0
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = triplet(arr);
    cout<<"The Triplets are : "<<endl;
    for(int i = 0 ; i < res.size() ; i++) {
        for(int j = 0 ; j < res[i].size() ; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// The Triplets are : 
// -1 -1 2 
// -1 0 1 

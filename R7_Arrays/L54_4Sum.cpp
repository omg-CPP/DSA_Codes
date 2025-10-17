#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i = 0 ; i < n ; i++) {
        // skip the duplicates
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for(int j = i+1 ; j < n ; j++) {
            // skip the duplicates
            if(j > i+1 && nums[j] == nums[j-1]) {
                continue;
            }

            int k = j+1;
            int l = n-1;
            while(k < l) {
                long long sum = 0;
                sum += nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if(sum == target) {
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // Skip the duplicates
                    while(k < l && nums[k] == nums[k-1]) {
                        k++;
                    }
                    // Skip the duplicates
                    while(k < l && nums[l] == nums[l+1]) {
                        l--;
                    }
                }
                else if(sum < target) {
                    k++;
                }
                else { // sum > target
                    l--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    vector<vector<int>> res = fourSum(nums,target);
    cout<<"The Quadruplets are : "<<endl;
    for(int i = 0 ; i < res.size() ; i++) {
        for(int j = 0 ; j < res[i].size() ; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// The Quadruplets are : 
// 1 1 3 4 
// 1 2 2 4 
// 1 2 3 3 
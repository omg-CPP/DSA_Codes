// Leetcode : 448 : Easy

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

#include <iostream>
#include <vector>
using namespace std;

// O(N) 
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    // visit nums[i] in the array and mark as nums[i]-1
    for(int i = 0 ; i < n ; i++) {
        // convert the array to 0 based indexing to mark n
        int idx = abs(nums[i]) - 1; 
        if(nums[idx] > 0) {
            nums[idx] = -nums[idx];
        }
    }

    for(int i = 0 ; i < n ; i++) {
        if(nums[i] > 0) {
            // again converting to 1 based indexing
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> disappeared = findDisappearedNumbers(nums);
    for(int i = 0 ; i < disappeared.size() ; i++) {
        cout<<disappeared[i]<<" ";
    }
    // 5 6 
    cout<<endl;
    return 0;
}

//        { 0, 1, 2, 3, 4, 5, 6, 7}
// nums = { 4, 3, 2, 7, 8, 2, 3, 1}
// nums = {-4,-3,-2,-7, 8, 2,-3,-1}
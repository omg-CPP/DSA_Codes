// Leetcode : 2460

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
vector<int> applyOperations(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for(int i = 0 ; i < n-1 ; i++) {
        if(nums[i] == nums[i+1]) {
            nums[i] *= 2;
            nums[i+1] = 0;
        }
    }
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] != 0) {
            ans.push_back(nums[i]);
            count++;
        }
    }
    for(int i = count ; i < n ; i++) {
        ans.push_back(0);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,2,2,1,1,0};
    vector<int> ans = applyOperations(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 4 2 0 0 0 
    cout<<endl;
    return 0;
}
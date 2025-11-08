#include <iostream>
#include <vector>
using namespace std;
// Leetcode 1480
// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

vector<int> runningSumBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> run(n);
    run[0] = nums[0];
    for(int i = 1 ; i < n ; i++) {
        run[i] = run[i-1] + nums[i];
    }
    return run;
}

// without using extra array
// time : O(n)
// space : O(1)
vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1 ; i < n ; i++) {
        nums[i] = nums[i-1] + nums[i];
    }
    return nums;
}


int main()
{
    vector<int> nums = {1,2,3,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 1 2 3 4 

    cout<<endl;
    vector<int> ans = runningSumBrute(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 3 6 10 

    cout<<endl;
    vector<int> res = runningSum(nums);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 3 6 10 

    return 0;
}
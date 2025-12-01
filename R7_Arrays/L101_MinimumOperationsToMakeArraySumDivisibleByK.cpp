// Leetcode : 3512 : Easy

#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    int sum = 0;
    for(int i = 0 ; i < nums.size() ; i++) {
        sum += nums[i];
    }
    return sum % k;
}

int main()
{
    vector<int> nums = {3,9,7};
    int k = 5;
    cout<<minOperations(nums,k); // 4
    return 0;
}

// sum = 14, k = 5
// sum = 14 + 1 = 15 => Not Possible
// sum = 14 - 4 = 10 => Possible
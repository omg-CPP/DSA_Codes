// Leetcode : 16
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// Two Pointers
// T.C. = O(nlogn) + o(n^2) = o(n^2)
// S.C. = O(1)
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int closestSum = 100000;
    sort(begin(nums),end(nums)); // O(nlogn)
    // [-4 -1 1 2]
    for(int i = 0 ; i < n-2 ; i++) {
        int j = i+1;
        int k = n-1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(abs(target-closestSum) > abs(target-sum)) {
                closestSum = sum;
            }
            if(sum < target) {
                j++;
            }
            else { // sum > target
                k--;
            }
        }
    }
    return closestSum;
}

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout<<threeSumClosest(nums,target)<<endl; // 2
    return 0;
}
// Leetcode : 930
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Subarray Sum Equals K Approach : Prefix Sum and Hashing Approach
// T.C. = O(n) + O(n) + O(1) = O(2n) = O(n)
// S.C. = O(n) + O(n) = O(2n) = O(n)
int numSubarraysWithSum_Better(vector<int>& nums, int goal) {
    int n = nums.size();
    int count = 0;
    unordered_map<int,int> mp;
    vector<int> prefixSum(n,0);
    prefixSum[0] = nums[0];
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    for(int j = 0 ; j < n ; j++) {
        if(prefixSum[j] == goal) {
            count++;
        }
        // K = subarraySum(i,j) = prefixSum[j] - prefixSum[i-1]
        // prefixSum[i-1] = prefixSum[j] - K
        int val = prefixSum[j] - goal;
        // If value is present in the map
        if(mp.find(val) != mp.end()) {
            count += mp[val];
        }
        // If value is not present in the map
        if(mp.find(prefixSum[j]) == mp.end()) {
            mp[prefixSum[j]] = 0;
        }
        // updating the frequency of element
        mp[prefixSum[j]]++;
    }
    return count;
}

// Sliding Window Approach : Efficient
// T.C. = O(n)
// S.C. = O(1)
int numSubarraysWithSum_Optimal(vector<int>& nums, int goal) {
    int n = nums.size();
        int count = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        while(j < n) {
            sum += nums[j];
            // Handle case where sum exceeds goal
            while(i < j && sum > goal) {
                // window shrink
                sum -= nums[i];
                i++;
            }
            
            // Count subarrays when sum equals goal
            if(sum == goal) {
                count++;
                // Count additional subarrays from leading zeros
                int temp = i;
                while(temp < j && nums[temp] == 0) {
                    count++;
                    temp++;
                }
            }
            j++;
        }
        return count;
}

// T.C. = 2*[O(n) + O(n)] = O(2n)
// S.C. = O(1)

int numSubarraysWithSum(vector<int>& nums, int goal) {
    if(goal < 0) {
        return 0;
    }
    int n = nums.size();
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += nums[j];
        // window shrink
        while(i <= j && sum > goal) {
            sum -= nums[i];
            i++;
        }
        count += (j-i+1);
        j++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout<<numSubarraysWithSum_Better(nums,goal)<<endl; // 4
    cout<<numSubarraysWithSum_Optimal(nums,goal)<<endl; // 4
    // fun(nums,2) - fun(nums,1)
    // fun(nums,2) = all subarrays with sum <= 2
    // fun(nums,1) = all subarrays with sum <= 1
    // fun(nums,2) - fun(nums,1) = all subarrays with sum == 2
    cout<<numSubarraysWithSum(nums,goal)-
    numSubarraysWithSum(nums,goal-1)<<endl; // 4
    return 0;
}
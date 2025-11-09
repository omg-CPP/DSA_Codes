// Leetcode : 974

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force Approach
// T.C. = O(n^3)
// S.C. = O(1)
int subarraysDivByK_BruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j++) {
            int sum = 0;
            for(int k = i ; k <= j ; k++) {
                sum += nums[k];
            }
            if(sum % k == 0) {
                count++;
            }
        }
    }
    return count;
}

// Better Approach
// T.C. = O(n^2)
// S.C. = O(1)
int subarraysDivByK_Better(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        int sum = 0;
        for(int j = i ; j < n ; j++) {
            sum += nums[j];
            if(sum % k == 0) {
                count++;
            }
        }
    }
    return count;
}

// Optimal Approach
// T.C. = O(n) + O(1) = O(n)
// S.C. = O(n)
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> mp; // rem, count
    int sum = 0;
    mp[0] = 1; // as initially sum = 0 => rem = 0 => so count = 0
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += nums[i];
        int rem = sum % k;
        if(rem < 0) {
            rem = rem + k;
        }
        // if we have seen the remainder before
        if(mp.find(rem) != mp.end()) {
            count += mp[rem];
        }
        mp[rem]++;
    }
    return count;
}

// if rem = -ve = -4
// suppose k = 7
// sum = 7n - 4 => (7n - 4 ) / 7 = -4 as rem
// so replace 7n - 4 + 7 - 7 = 7n - 7 - 4 + 7 = 7(n-1) -4 + k = 7(n-1) + 3


// eg = 122 / 7 :: +ve rem =  3 :: 119
//                 -ve rem = -4 :: 126

int main()
{
    vector<int> nums = {4,5,0,-2,-3,1};
    cout<<subarraysDivByK_BruteForce(nums,5)<<endl; // 7
    cout<<subarraysDivByK_Better(nums,5)<<endl; // 7
    cout<<subarraysDivByK(nums,5)<<endl; // 7
    return 0;
}
// Leetcode : 2799
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n)
// S.C. = O(n) + O(n) = O(2n)

int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    // Using a set to find all unique elements of the array
    unordered_set<int> st(begin(nums),end(nums));
    int c = st.size(); // size of the set
    // Using a map to store frequencies of the elements of the array
    unordered_map<int,int> mp;
    int count = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        mp[nums[j]]++; // updating the frequency of the current element
        while(mp.size() == st.size()) { 
            // mark your ans
            count += n-j;
            // window shrink
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,3,1,2,2};
    int count = countCompleteSubarrays(nums);
    cout<<count<<endl; // 4
    return 0;
}
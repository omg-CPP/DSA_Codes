// Leetcode : 496

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // key : value
    // 1 : 3
    // 3 : 4
    // 4 : -1
    // 2 : -1
    unordered_map<int,int> m; // (nums2[i],nge) pair
    stack<int> st;
    m[nums2[nums2.size()-1]] = -1;
    st.push(nums2[nums2.size()-1]);
    for(int i = nums2.size()-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && nums2[i] >= st.top()) {
            st.pop();
        }
        if(st.size() == 0) {
            m[nums2[i]] = -1;
        }
        else {
            m[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }

    vector<int> nge;
    for(int i = 0 ; i < nums1.size() ; i++) {
        nge.push_back(m[nums1[i]]);
    }
    return nge;
}

int main()
{
    return 0;
}
// Leetcode : 503

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    // 1  2  3  4  3 -> nums[]
    // 2  3  4 -1  4 -> nge[]

    // 0  1  2  3  4  5  6  7  8  9
    // 1  2  3  4  3  1  2  3  4  3 

    // step 1 : Hypothetical Array Visualisation
    int n = nums.size();
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i = 2*n-1 ; i >= 0 ; i--) {
        // step 2 : popping condition
        while(st.size() > 0 && nums[i%n] >= st.top()) {
            st.pop();
        }
        // step 3 : nge array formation
        if(i < n) {
            if(!st.empty()) {
                nge[i] = st.top();
            }
        }
        st.push(nums[i%n]);
    }
    return nge;
}

int main()
{
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 2 3 4 -1 4 
    cout<<endl;
    return 0;
}
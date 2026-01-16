// Leetcode : 239

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// T.C. = O((n-k+1)*(k)) = O(kn)
// S.C. = O(1)
// Time Limit Exceeded 
vector<int> maxSlidingWindow_Naive(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
    // no of windows = n-k+1
    for(int i = 0 ; i < n-k+1 ; i++) { // O(n-k+1)
        int mx = INT_MIN;
        for(int j = i ; j < i+k ; j++) { // O(k)
            mx = max(mx,nums[j]);
        }
        ans.push_back(mx);
    }
    return ans;
}

// Using Stack [Next Greater Element Index]
// No of operations = (n-k+1)*(k)
// T.C. = O(kn) in worst case
// S.C. = O(n) : stack
vector<int> maxSlidingWindow_Better(vector<int>& nums, int k) {
    // calculating the ngei array
    int n = nums.size();
    vector<int> ngei(n,0);
    stack<int> st;
    st.push(n-1);
    ngei[n-1] = n;
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && nums[i] >= nums[st.top()]) {
            st.pop();
        }
        if(st.size() == 0) {
            ngei[i] = n;
        }
        else {
            ngei[i] = st.top();
        }
        st.push(i);
    }

    vector<int> ans;
    for(int i = 0 ; i < n-k+1 ; i++) {
        int mx = nums[i];
        int j = i;
        while(j < i+k) { // if nge is inside window
            mx = nums[j];
            j = ngei[j];
        }
        ans.push_back(mx);
    }
    return ans;
}

// Monotinic Decreasing : Deque
// T.C. = O(n) : In Deque, any element is pushed or popped only once
// S.C. = O(n)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // calculating the ngei array
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for(int i = 0 ; i < n ; i++) {
        // step 1 : make space for nums[i]
        while(dq.size() != 0 && dq.front() <= i-k) {
            dq.pop_front();
        }
        // step 2 : 
        while(dq.size() != 0 && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        // step 3 : 
        dq.push_back(i);
        // step 4 : Mark ans
        if(i >= k-1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}


int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 3 3 5 5 6 7 
    cout<<endl;
    return 0;
}
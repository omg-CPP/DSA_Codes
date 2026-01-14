// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Next Smaller Element Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Reverse Loop traversal to acheive Linear Time Complexity

vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n,0); // nge -> next smaller element array
    stack<int> st;
    nse[n-1] = -1;
    st.push(nums[n-1]);
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && nums[i] <= st.top()) {
            st.pop();
        }
        if(st.size() == 0) {
            nse[i] = -1;  // No next smaller element exist for this particular element
        }
        else { // st.size() != 0
            nse[i] = st.top();
        }
        st.push(nums[i]);
    }
    return nse;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = nextSmallerElement(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 1 0 0 -1 2 -1 5 4 -1 
    cout<<endl;
    return 0;
}
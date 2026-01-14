// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Previous Greater Element Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Forward Loop traversal to acheive Linear Time Complexity

vector<int> previousGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n,0); // pge -> previous greater element array
    stack<int> st;
    pge[0] = -1;
    st.push(nums[0]);
    for(int i = 1 ; i < n ; i++) {
        while(st.size() > 0 && nums[i] >= st.top()) {
            st.pop();
        }
        if(st.size() == 0) {
            pge[i] = -1;  // No previous greater element exist for this particular element
        }
        else { // st.size() != 0
            pge[i] = st.top();
        }
        st.push(nums[i]);
    }
    return pge;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = previousGreaterElement(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // -1 -1 7 -1 9 9 6 9 8 5 
    cout<<endl;
    return 0;
}
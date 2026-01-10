#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// M2 : Using Stack
// T.C. = O(n + n) = O(2n) = O(n)
// Because it is pushed or popped only once 
// So Total = O(n) stack operations for complete outer for loop
// S.C. = O(n)
// POP -> ANS -> PUSH
vector<int> previousGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,0);
    stack<int> st;
    ans[0] = -1;
    st.push(nums[0]);
    for(int i = 1 ; i < n ; i++) {
        // pop all the elements smaller than or equal to num[i]
        while(st.size() > 0 && st.top() <= nums[i]) {
            st.pop();
        }
        // mark the ans in result vector
        if(st.size() == 0) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }
        // push that particular nums[i] for next iteration
        st.push(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> v = {3,1,2,7,4,6,2,3};
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 3 1 2 7 4 6 2 3 
    cout<<endl;

    vector<int> res = previousGreaterElement(v);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    // -1 3 3 -1 7 7 6 6 
    cout<<endl;
    return 0;
}
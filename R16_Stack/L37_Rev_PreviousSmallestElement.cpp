// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Previous Smallestt Element Array Construction
// T.C. = O(n)
// S.C. = O(1)
// Forward Loop Traversal for Linear Time Complexity

vector<int> previousSmallestElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n,0); // pse -> previous smallest element array
    pse[0] = -1;
    int min = nums[0];
    for(int i = 1 ; i < n ; i++) {
        pse[i] = min;
        if(nums[i] < min) {
            min = nums[i];
        }
    }
    return pse;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = previousSmallestElement(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // -1 3 3 1 1 0 0 0 0 0 
    cout<<endl;
    return 0;
}
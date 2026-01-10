// Leetcode : Leetcode 84
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> psi(n,0);
    stack<int> st;
    psi[0] = -1;
    st.push(0);
    for(int i = 1 ; i < n ; i++) {
        // pop all the elements smaller than or equal to num[i]
        while(st.size() > 0 && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        // mark the ans in result vector
        if(st.size() == 0) {
            psi[i] = -1;
        }
        else {
            psi[i] = st.top();
        }
        // push that particular nums[i] for next iteration
        st.push(i);
    }
    return psi;
}

vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nsi(n,0);
    stack<int> st;
    nsi[n-1] = n;
    st.push(n-1);
    for(int i = n-2 ; i >= 0 ; i--) {
        // pop all the elements smaller than or equal to num[i]
        while(st.size() > 0 && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        // mark the ans in result vector
        if(st.size() == 0) {
            nsi[i] = n;
        }
        else {
            nsi[i] = st.top();
        }
        // push that particular nums[i] for next iteration
        st.push(i);
    }
    return nsi;
}

int largestRectangleArea(vector<int>& heights) {
    int maxArea = INT_MIN;
    int n = heights.size();
    vector<int> psi = previousSmallerElement(heights);
    vector<int> nsi = nextSmallerElement(heights);
    for(int i = 0 ; i < n ; i++) {
        int area = heights[i] * (nsi[i]-psi[i]-1);
        if(area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

int main()
{
    vector<int> v = {2,1,5,6,2,3};
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 2 1 5 6 2 3
    cout<<endl;

    vector<int> psi = previousSmallerElement(v);
    for(int i = 0 ; i < psi.size() ; i++) {
        cout<<psi[i]<<" ";
    }
    // -1 -1 1 2 1 4 
    cout<<endl;

    vector<int> nsi = nextSmallerElement(v);
    for(int i = 0 ; i < nsi.size() ; i++) {
        cout<<nsi[i]<<" ";
    }
    // 1 6 4 4 6 6 
    cout<<endl;

    int maxArea = largestRectangleArea(v);
    cout<<maxArea<<endl; // 10
    return 0;
}
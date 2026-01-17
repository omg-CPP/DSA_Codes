// Leetcode : Leetcode 88

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Max Rectangle in Binary Matrix with all 1's

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// T.C. = 2 * O(2N) + O(N) = O(4N) + O(N) = O(5N)
// S.C. = O(2N) + O(2N) = O(4N)

// T.C. = O(2N)
vector<int> previousSmallerElementIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> psei(n,-1);
    stack<int> st;
    st.push(0);
    for(int i = 1 ; i < n ; i++) {
        while(st.size() > 0 && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(st.size() == 0) {
            psei[i] = -1;
        }
        else {
            psei[i] = st.top();
        }
        st.push(i);
    }
    return psei;
}

// T.C. = O(2N)
vector<int> nextSmallerElementIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> nsei(n,n);
    stack<int> st;
    st.push(n-1);
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(st.size() == 0) {
            nsei[i] = n;
        }
        else {
            nsei[i] = st.top();
        }
        st.push(i);
    }
    return nsei;
}

// T.C. = O(N)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> psei = previousSmallerElementIndex(heights);
    vector<int> nsei = nextSmallerElementIndex(heights);
    int maxArea = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int area = heights[i] * (nsei[i]-psei[i]-1);
        if(area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}


// Binary 2D MATRIX
int maximalRectangle(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // compute area for first row
    int area = largestRectangleArea(matrix[0]);
    for(int i = 1 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            // row update : by adding previous row's value
            if(matrix[i][j] != 0) {
                matrix[i][j] = matrix[i][j] + matrix[i-1][j];
            }
            else {
                matrix[i][j] = 0;
            }
        }
        // entire row is updated now
        area = max(area,largestRectangleArea(matrix[i]));
    }
    return area;
}

int main()
{
    // vector<vector<char>> matrix = {{'1','0','1','0','0'},
    //                                {'1','0','1','1','1'},
    //                                {'1','1','1','1','1'},
    //                                {'1','0','0','1','0'}};
    vector<vector<int>> matrix = {{1,0,1,0,0},
                                   {1,0,1,1,1},
                                   {1,1,1,1,1},
                                   {1,0,0,1,0}};
    int maxArea = maximalRectangle(matrix);
    cout<<maxArea<<endl; // 6
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Celebrity knows no one
// Everyone knows celebrity
// Ignore diagonals

// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n)
// S.C. = O(n)

int celebrity(vector<vector<int>>& mat) {
    // mat : square matrix n*n
    int n = mat.size();
    stack<int> st;
    // pushing all people into stack
    for(int i = 0 ; i < n ; i++) {
        st.push(i);
    }
    // finding the celebrity
    while(st.size() > 1) {
        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();
        if(mat[p1][p2] == 0) {
            st.push(p1);
        }
        else { // mat[p1][p2] == 1
            st.push(p2);
        }
    }
    // confirming the celebrity
    int star = st.top();
    for(int i = 0 ; i < n ; i++) {
        if((i != star) && (mat[i][star] == 0 || mat[star][i] == 1)) {
            return -1;
        }
    }
    return star;
}

int main()
{
    vector<vector<int>> mat = {{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
    int star = celebrity(mat);
    cout<<star<<endl; // 1
    return 0;
}
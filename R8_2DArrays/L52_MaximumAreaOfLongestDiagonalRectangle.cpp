// Leetcode : 3000
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int n = dimensions.size();
    int maxDiag = 0;
    int maxArea = 0;

    for(int i = 0 ; i < n ; i++) {

        int l = dimensions[i][0];
        int w = dimensions[i][1];

        int diag = l*l + w*w; // neglected sqrt as we are comparing
        int area = l*w;

        if(diag > maxDiag) {
            maxDiag = diag;
            maxArea = area;
        }
        else if(diag == maxDiag) {
            maxArea = max(maxArea,area);
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> dimensions = {{9,3},{8,6}};
    cout<<areaOfMaxDiagonal(dimensions)<<endl; // 48
    return 0;
}
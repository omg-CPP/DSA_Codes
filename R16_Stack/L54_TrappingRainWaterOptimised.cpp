#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

// T.C. = O(n)
// S.C. = O(1)
int trap(vector<int>& height) {
    int n = height.size();
    
    // step 1 : mark l, r, lmax, rmax, water
    int l = 0;
    int r = n-1;
    int lmax = 0;
    int rmax = 0;
    int water = 0;

    // step 2 : Apply Two Pointers
    while(l < r) {

        // step 3 : calcluate lmax and rmax at each iteration
        lmax = max(lmax,height[l]);
        rmax = max(rmax,height[r]);

        if(lmax < rmax) {
            // water storage is dominated by lmax
            water = water + (lmax - height[l]);
            l++;
        }
        else {
            // water storage is dominated by rmax
            water = water + (rmax - height[r]);
            r--;
        }
    }
    return water;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    for(int i = 0 ; i < height.size() ; i++) {
        cout<<height[i]<<" ";
    }
    // 0 1 0 2 1 0 1 3 2 1 2 1 
    cout<<endl;

    int water = trap(height);
    cout<<"The rain water trapped is : "<<water<<endl;
    // The rain water trapped is : 6
    return 0;
}
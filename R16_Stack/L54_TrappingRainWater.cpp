#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

vector<int> previousGreatestElement(vector<int>& height) {
    int n = height.size();
    vector<int> pge(n,0);
    pge[0] = -1;
    int max = height[0];
    for(int i = 1 ; i < n ; i++) {
        pge[i] = max;
        if(max < height[i]) {
            max = height[i];
        }
    }
    return pge;
}

vector<int> nextGreatestElement(vector<int>& height) {
    int n = height.size();
    vector<int> nge(n,0);
    nge[n-1] = -1;
    int max = height[n-1];
    for(int i = n-2 ; i >= 0 ; i--) {
        nge[i] = max;
        if(max < height[i]) {
            max = height[i];
        }
    }
    return nge;
}

// T.C. = O(n)
// S.C. = O(n)

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> pge = previousGreatestElement(height);
    vector<int> nge = nextGreatestElement(height);
    int water = 0;
    for(int i = 0 ; i < n ; i++) {
        if(min(pge[i],nge[i]) > height[i]) {
            water = water + min(pge[i],nge[i]) - height[i];
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

    vector<int> pge = previousGreatestElement(height);
    for(int i = 0 ; i < pge.size() ; i++) {
        cout<<pge[i]<<" ";
    }
    // -1 0 1 1 2 2 2 2 3 3 3 3 
    cout<<endl;

    vector<int> nge = nextGreatestElement(height);
    for(int i = 0 ; i < nge.size() ; i++) {
        cout<<nge[i]<<" ";
    }
    // 3 3 3 3 3 3 3 2 2 2 1 -1 
    cout<<endl;

    int trappedWater = trap(height);
    cout<<trappedWater<<endl; // 6
    return 0;
}
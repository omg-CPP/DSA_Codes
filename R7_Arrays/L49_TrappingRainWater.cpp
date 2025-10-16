#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trappingRainWater(vector<int> height) {
    int n = height.size();
    
    // creating previous greatest elemnent array
    int pge[n];
    pge[0] = -1;
    int maxp = height[0];
    for(int i = 1 ; i < n ; i++) {
        pge[i] = maxp;
        if(maxp < height[i]) {
            maxp = height[i];
        }
    }

    // creating next greatest elemnent array
    int nge[n];
    nge[n-1] = -1;
    int maxn = height[n-1];
    for(int i = n-2 ; i >= 0 ; i--) {
        nge[i] = maxn;
        if(maxn < height[i]) {
            maxn = height[i];
        }
    }

    // creating minimum array
    int mini[n];
    for(int i = 0 ; i < n ; i++) {
        mini[i] = min(pge[i],nge[i]);
    }

    // calculating water
    int water = 0;
    for(int i = 0 ; i < n ; i++) {
        if(height[i] < mini[i]) {
            water = water + (mini[i]-height[i]);
        }
    }
    return water;
}

int main()
{
    vector<int> height;
    int n;
    cout<<"Enter no of buildings : ";
    cin>>n;
    cout<<"Enter heights of buildings : ";
    for(int i = 0 ; i < n ; i++) {
        int b;
        cin>>b;
        height.push_back(b);
    }

    int water = trappingRainWater(height);

    cout<<"The amount of water trapped is : "<<water<<endl;
    return 0;
}

// Enter no of buildings : 12
// Enter heights of buildings : 0 1 0 2 1 0 1 3 2 1 2 1
// The amount of water trapped is : 6

// Enter no of buildings : 6
// Enter heights of buildings : 4 2 0 3 2 5
// The amount of water trapped is : 9
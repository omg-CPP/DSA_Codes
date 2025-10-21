// Leetcode : 452
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// T.C. = O(n) + O(nlogn) = O(nlogn)
// S.C. = O(1)
int findMinArrowShots(vector<vector<int>>& points) {
    // prevEP > currSP => Overlap
    // currSP > prevSP => No Overlap
    int n = points.size();
    sort(begin(points),end(points));
    vector<int> prev = points[0];
    int count = 1;
    for(int i = 1 ; i < n ; i++) {
        int prevSP = prev[0];
        int prevEP = prev[1];

        int currSP = points[i][0];
        int currEP = points[i][1];

        if(prevEP < currSP) { // No Overlap
            count++;
            prev = points[i];
        }
        else { // prevEP > currSP => Overlap
            // overlapping region
            prev[0] = max(prevSP,currSP);
            prev[1] = min(prevEP,currEP);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int arrows = findMinArrowShots(points);
    cout<<arrows<<endl;
    return 0;
}
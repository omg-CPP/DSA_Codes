// Leetcode : 3027  :: same code as part 1 :: leetcode 3025

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int numberOfPairs(vector<vector<int>>& points) {
    int n = points.size();
    int result = 0;

    // O(nlogn)
    // custom sorting using lambda function
    auto lambda = [](vector<int>& point1, vector<int>& point2) {
        // if x - coordinates are same
        if(point1[0] == point2[0]) {
            // sort them with decreasing y
            return point1[1] > point2[1];
        }
        // sort them with increasing x
        return point1[0] < point2[0];
    };

    sort(points.begin(),points.end(),lambda);

    for(int i = 0 ; i < n ; i++) {
        // let it be A
        int x1 = points[i][0];
        int y1 = points[i][1];

        int maxY = INT_MIN;
        // finding B : lower right points
        for(int j = i+1 ; j < n ; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];

            if(y2 > y1) { // uper chala gaya A se
                continue;
            }

            if(y2 > maxY) {
                result++;
                maxY = y2;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> points = {{6,2},{4,4},{2,6}};
    cout<<numberOfPairs(points)<<endl;  // 2
    return 0;
}
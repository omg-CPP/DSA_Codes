// Leetcode : 3025

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// T.C. : O(n^3)
// S.C. : O(1)
int numberOfPairsBruteForce(vector<vector<int>>& points) {
    int n = points.size();
    int result = 0;
    for(int i = 0 ; i < n ; i++) {
        // let it be A
        int x1 = points[i][0];
        int y1 = points[i][1];

        // finding B
        for(int j = 0 ; j < n ; j++) {
            if(i == j) {
                continue;
            }
            int x2 = points[j][0];
            int y2 = points[j][1];

            // valid pair
            if(x1 <= x2 && y1 >= y2) {
                bool hasPointsInside = false;
                for(int k = 0 ; k < n ; k++) {
                    // we need to check for points other than A and B
                    if(k == i || k == j) {
                        continue;
                    }

                    // checking for any other third point inside the rectangle
                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    if(x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                        hasPointsInside = true;
                        break;
                    }
                }
                // point is not inside the rectangle
                if(hasPointsInside == false) {
                    result++;
                }
            }
        }
    }
    return result;
}


// T.C. : O(nlogn + n^2) = O(n^2)
// S.C. : O(1)
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

    // O(n^2)
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
    vector<vector<int>> points_2 = {{1,4},{1,3},{1,2},{2,4},{6,6}};
    cout<<numberOfPairsBruteForce(points)<<endl;  // 2
    cout<<numberOfPairs(points)<<endl;  // 2
    cout<<numberOfPairs(points_2)<<endl;
    return 0;
}


// [[6,2],[4,4],[2,6]]

// after custom sort

// [[2,6],[4,4],[6,2]]


// custom sort logic
// [[1,2],[1,3],[1,4],[2,4],[6,6]]
// in this [1,2],[1,3] is not a valid pair but [1,3],[1,2] could a valid pair.
// in this case, we first sort by x-coordinate. If x-coordinates are same, we sort by y-coordinate in decreasing order.
// [[1,4],[1,3],[1,2],[2,4],[6,6]]
// ans = 2 + 1 = 3
// this would make sure that we are not leaving any corner cases.
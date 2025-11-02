// -> Saddle Point : Element of the matrix such that it is the minimum element in its
//                   row and the maximum element in its column.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int saddlePoint(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int max = INT_MIN;
            int min = INT_MAX;

            // for each element checking is done individually

            // row traversing and finding minimum element
            for(int a = 0 ; a < n ; a++) {
                if(min > matrix[i][a]) {
                    min = matrix[i][a];
                }
            }

            // column traversing and finding maximum element
            for(int b = 0 ; b < m ; b++) {
                if(max < matrix[b][j]) {
                    max = matrix[b][j];
                }
            }

            // checking for saddle point
            if(min == matrix[i][j] && max == matrix[i][j]) {
                // cout<<matrix[i][j]<<" is a Saddle Point"<<endl;
                return matrix[i][j];
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> v = {{4,1,3},{9,7,8},{5,6,2}};
    cout<<"Matrix : "<<endl;
    for(int i = 0 ; i < v.size() ; i++) {
        for(int j = 0 ; j < v[i].size() ; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int saddle = saddlePoint(v);
    cout<<saddle<<" is the Saddle Point of the Matrix"<<endl;
    return 0;
}

// Matrix : 
// 4 1 3 
// 9 7 8 
// 5 6 2 

// 7 is the Saddle Point of the Matrix
#include <iostream>
#include <vector>
// Approach 2 : bottom-left corner start
using namespace std;

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = rows-1;
    int j = 0;
    while(i >= 0 && j <= cols-1) {
        if(matrix[i][j] == target) {
            return true;
        }
        else if(matrix[i][j] < target) {
            j++;
        }
        else { // matrix[i][j] > target
            i--;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target;
    cout<<"Enter target value : ";
    cin>>target;
    bool flag = searchMatrix(matrix,target);
    cout<<flag<<endl;
    return 0;
}

// Enter target value : 5
// 1 : true

// Enter target value : 20
// 0 : false

// Enter target value : 22
// 1 : true
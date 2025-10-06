#include <iostream>
#include <vector>
using namespace std;
int main()
{

    // for loop in arrays

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 1 2 3 4 5 

    cout<<endl;

    // for loop in vectors

    vector<int> v1 = {1, 2, 3, 4, 5};
    for (int i = 0 ; i < v1.size() ; i++) {
        cout<<v1[i]<<" ";
    }
    // 1 2 3 4 5 

    cout<<endl;

    // for auto loop in arrays

    int brr[] = {1, 2, 3, 4, 5};
    for (auto x : brr) {
        cout<<x<<" ";
    }
    // 1 2 3 4 5 

    cout<<endl;

    // for auto loop in vectors

    vector<int> v2 = {1, 2, 3, 4, 5};
    for (auto x : v2) {
        cout<<x<<" ";
    }
    // 1 2 3 4 5 

    cout<<endl;

    // for loop for 2D Arrays

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int r = sizeof(matrix) / sizeof(matrix[0]);
    int c = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 4 5 6 
    // 7 8 9 

    cout<<endl;

    // for loop for 2D vectors

    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0 ; i < mat.size() ; i++) {
        for (int j = 0 ; j < mat[i].size() ; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<endl;

    // ********************************************************************

    // Arrays passed by reference *****************************************

    int crr[] = {1, 2, 3, 4, 5};
    for(int i = 0 ; i < 5 ; i++) {
        crr[i] += 1;
    }
    for(int i = 0 ; i < 5 ; i++) {
        cout<<crr[i]<<" ";
    }
    // 2 3 4 5 6

    cout<<endl;

    // Vectors passed by value *******************************************

    vector<int> v3 = {1, 2, 3, 4, 5};
    for(auto x : v3) {
        x += 1;
    }
    for(auto x : v3) {
        cout<<x<<" ";
    }
    // 1 2 3 4 5

    cout<<endl;

    // Vectors passed by reference *******************************************

    vector<int> v4 = {1, 2, 3, 4, 5};
    for(auto& x : v4) {
        x += 1;
    }
    for(auto x : v4) {
        cout<<x<<" ";
    }
    // 2 3 4 5 6
    
    cout<<endl;

    // **************************************************************

    int drr[] = {1, 2, 3, 4, 5};
    for(int i : drr) {
        cout<<i<<" ";
    }
    // 1 2 3 4 5

    cout<<endl;

    // ***************************************************************

    vector<int> v5 = {1, 2, 3, 4, 5};
    for(int& i : v5) {
        i += 1;
    }
    for(int i : v5) {
        cout<<i<<" ";
    }
    // 2 3 4 5 6

    cout<<endl;

    // ***************************************************************

    // for auto loop in 2D arrays

    int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for(auto& row : grid) {
        for(auto& element : row) {
            cout<<element<<" ";
        }
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<endl;

    // **************************************************************

    // for auto loop in 2D vectors

    vector<vector<int>> vec_grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for(auto& row : vec_grid) {
        for(auto& element : row) {
            cout<<element<<" ";
        }
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<endl;

    // **************************************************************

    int Grid_1[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for(auto& row : Grid_1) {
        int i = row[0];
        int j = row[1];
        cout<<i<<" "<<j<<endl;
    }
    // 1 2
    // 3 4
    // 5 6

    cout<<endl;

    // **************************************************************

    vector<vector<int>> Grid_2 = {{1,2},{3,4},{5,6}};
    for(auto& row : Grid_2) {
        int i = row[0];
        int j = row[1];
        cout<<i<<" "<<j<<endl;
    }
    // 1 2
    // 3 4
    // 5 6

    cout<<endl;

    // **************************************************************


    return 0;
}

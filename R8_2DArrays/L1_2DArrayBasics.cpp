#include <iostream>
using namespace std;
int main()
{
    // Declaration of 2D Array
    int arr[3][3];
    // rows = 3 (0-2)
    // cols = 3 (0-2)
    arr[0][0] = 4;
    cout<<arr[0][0]<<endl; // 4

    int grid[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // array of arrays = 2D array
    cout<<grid[1][2]<<endl; // 6

    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 4 5 6 
    // 7 8 9 

    int m;
    cout<<"Enter no of rows : ";
    cin>>m;
    int n;
    cout<<"Enter no of columns : ";
    cin>>n;
    int grid[m][n];

    cout<<"Enter elements of grid : ";
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>grid[i][j];
        }
    }

    cout<<"The Grid is : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 2
// Enter no of columns : 3
// Enter elements of grid : 1 2 3 4 5 6
// The Grid is : 
// 1 2 3 
// 4 5 6 

// Enter no of rows : 3 
// Enter no of columns : 3
// Enter elements of grid : 
// 1 2 3
// 4 5 6
// 7 8 9
// The Grid is : 
// 1 2 3 
// 4 5 6 
// 7 8 9 
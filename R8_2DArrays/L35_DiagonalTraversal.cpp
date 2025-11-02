// Print matrix in zig-zag fashion : GFG
// Diagonal Traverse 1 : Leetcode 498

#include <iostream>
using namespace std;
int main()
{
    // Square Matrix
    int n;
    cout<<"Enter rows/columns : ";
    cin>>n;

    int arr[n][n];
    cout<<"Enter arr elements : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<endl;

    cout<<"arr Matrix : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    // g = gap
    // refer ipad
    for(int g = 0 ; g < n ; g++) {
        for(int i = 0, j = g ; j < n ; i++, j++) {
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}

// Enter rows/columns : 6
// Enter arr elements : 
// 00 01 02 03 04 05   
// 10 11 12 13 14 15
// 20 21 22 23 24 25
// 30 31 32 33 34 35
// 40 41 42 43 44 45
// 50 51 52 53 54 55

// arr Matrix : 
// 0 1 2 3 4 5 
// 10 11 12 13 14 15 
// 20 21 22 23 24 25 
// 30 31 32 33 34 35 
// 40 41 42 43 44 45 
// 50 51 52 53 54 55 

// 0 11 22 33 44 55 1 12 23 34 45 2 13 24 35 3 14 25 4 15 5 

// Enter rows/columns : 3
// Enter arr elements : 
// 1 2 3
// 4 5 6
// 7 8 9

// arr Matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 

// 1 5 9 2 6 3 

// Enter rows/columns : 4
// Enter arr elements : 
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// arr Matrix : 
// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
// 13 14 15 16 

// 1 6 11 16 2 7 12 3 8 4 
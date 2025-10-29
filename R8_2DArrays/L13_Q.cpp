// Given a matrix ‘matrix’ of dimension m*n and 2 coordinates (x1, y1) and (x2, y2). Return the sum of the
// rectangle from (x1,y1) to (x2,y2).

// Particular Region Sum

#include <iostream>
using namespace std;
int main()
{
    int m;
    cout<<"Enter rows : ";
    cin>>m;
    int n;
    cout<<"Enter columns : ";
    cin>>n;

    int matrix[m][n];
    cout<<"Enter matrix elements : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>matrix[i][j];
        }
    }

    cout<<endl;

    cout<<"Matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int x1,x2,y1,y2;
    cout<<"Enter (x1,y1) : ";
    cin>>x1>>y1;
    cout<<"Enter (x2,y2) : ";
    cin>>x2>>y2;

    int sum = 0;
    for(int i = x1 ; i <= x2 ; i++) {
        for(int j = y1 ; j <= y2 ; j++) {
            sum = sum + matrix[i][j];
        }
    }

    cout<<"The Sum from (x1,y1) to (x2,y2) is : "<<sum<<endl;

    return 0;
}

// Enter rows : 5
// Enter columns : 4
// Enter matrix elements : 
// 1 9 17 10
// 13 2 20 5
// 3 11 18 14
// 19 6 16 8
// 7 15 4 12

// Matrix : 
// 1 9 17 10 
// 13 2 20 5 
// 3 11 18 14 
// 19 6 16 8 
// 7 15 4 12 

// Enter (x1,y1) : 0 1
// Enter (x2,y2) : 3 3
// The Sum from (x1,y1) to (x2,y2) is : 136

// Enter rows : 4
// Enter columns : 4
// Enter matrix elements : 
// 1 2 -3 4
// 0 0 -4 2
// 1 -1 2 3
// -4 -5 -7 0

// Matrix : 
// 1 2 -3 4 
// 0 0 -4 2 
// 1 -1 2 3 
// -4 -5 -7 0 

// Enter (x1,y1) : 1 2
// Enter (x2,y2) : 3 3
// The Sum from (x1,y1) to (x2,y2) is : -4
// Write a program to print the column number having the maximum sum in a given matrix.

#include <iostream>
#include <climits>
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

    // m = 3 & n = 4
    int max_sum = INT_MIN;
    int column = -1;
    // column wise printing
    for(int j = 0 ; j < n ; j++) {
        int sum = 0;
        for(int i = 0 ; i < m ; i++) {
            sum = sum + matrix[i][j];
        }
        if(max_sum < sum) {
            max_sum = sum;
            column = j;
        }
        // max_sum = max(max_sum,sum);
    }
    cout<<"Max Sum : "<<max_sum<<" at index : "<<column<<endl;
    return 0;
}

// Enter rows : 5 
// Enter columns : 5
// Enter matrix elements : 
// 1 2 3 4 5
// 5 3 1 4 2
// 5 6 7 8 9
// 0 6 3 4 12
// 9 7 12 4 3

// Matrix : 
// 1 2 3 4 5 
// 5 3 1 4 2 
// 5 6 7 8 9 
// 0 6 3 4 12 
// 9 7 12 4 3 

// Max Sum : 31 at index : 4

// Enter rows : 3 
// Enter columns : 3
// Enter matrix elements : 
// 1 2 3
// 4 2 1
// 5 6 7

// Matrix : 
// 1 2 3 
// 4 2 1 
// 5 6 7 

// Max Sum : 11 at index : 2

// Enter rows : 3
// Enter columns : 4
// Enter matrix elements : 
// 1 2 3 4
// 4 6 7 8
// 9 10 11 12

// Matrix : 
// 1 2 3 4 
// 4 6 7 8 
// 9 10 11 12 

// Max Sum : 24 at index : 3
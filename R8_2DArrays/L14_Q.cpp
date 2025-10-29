// Write a program to print the row number having the maximum sum in a given matrix.

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

    int max_sum = INT_MIN;
    int row = -1;
    // row wise printing
    for(int i = 0 ; i < m ; i++) {
        int sum = 0;
        for(int j = 0 ; j < n ; j++) {
            sum = sum + matrix[i][j];
        }
        if(max_sum < sum) {
            max_sum = sum;
            row = i;
        }
        // max_sum = max(max_sum,sum);
    }
    cout<<"Max Sum : "<<max_sum<<" at index : "<<row<<endl;
    return 0;
}

// Input 1:
// 1 3 5 7
// 3 4 7 8
// 1 4 12 3

// Output : 1st index : Sum = 22


// Enter rows : 3
// Enter columns : 4
// Enter matrix elements : 
// 1 3 5 7
// 3 4 7 8
// 1 4 12 3

// Matrix : 
// 1 3 5 7 
// 3 4 7 8 
// 1 4 12 3 

// Max Sum : 22 at index : 1
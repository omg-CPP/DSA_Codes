#include <iostream>
using namespace std;
int main()
{
    int m;
    cout<<"Enter rows of matrix : ";
    cin>>m;
    int n;
    cout<<"Enter columns of matrix : ";
    cin>>n;

    int arr[m][n];
    cout<<"Enter elements of matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<endl;
    cout<<"matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"Spiral Form of Matrix : "<<endl;
    int min_row = 0;
    int min_col = 0;
    int max_row = m-1;
    int max_col = n-1;

    int tne = m*n;
    int count = 0;

    // if count == tne => what is the need to print then so count < tne

    while((min_row <= max_row) && (min_col <= max_col)) {
        // right
        for(int j = min_col ; j <= max_col && count < tne ; j++) {
            cout<<arr[min_row][j]<<" ";
            count++;
        }
        min_row++;

        // down
        for(int i = min_row ; i <= max_row && count < tne ; i++) {
            cout<<arr[i][max_col]<<" ";
            count++;
        }
        max_col--;

        // left
        for(int j = max_col ; j >= min_col && count < tne ; j--) {
            cout<<arr[max_row][j]<<" ";
            count++;
        }
        max_row--;

        // top
        for(int i = max_row ; i >= min_row && count < tne ; i--) {
            cout<<arr[i][min_col]<<" ";
            count++;
        }
        min_col++;
    }
    return 0;
}

// Enter rows of matrix : 3
// Enter columns of matrix : 4
// Enter elements of matrix : 
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12

// matrix : 
// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 

// Spiral Form of Matrix : 
// 1 2 3 4 8 12 11 10 9 5 6 7 


// Enter rows of matrix : 3
// Enter columns of matrix : 3
// Enter elements of matrix : 
// 1 2 3
// 4 5 6
// 7 8 9

// matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 

// Spiral Form of Matrix : 
// 1 2 3 6 9 8 7 4 5 
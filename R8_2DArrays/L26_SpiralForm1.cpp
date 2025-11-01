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

    while((min_row <= max_row) && (min_col <= max_col)) {
        // right
        // left to right
        // minr -> const
        // minc -> maxc
        for(int j = min_col ; j <= max_col ; j++) {
            cout<<arr[min_row][j]<<" ";
        }
        min_row++;
        if(min_row > max_row || min_col > max_col) {
            break;
        }

        // down
        // top to bottom
        // maxc -> const
        // minr -> maxr
        for(int i = min_row ; i <= max_row ; i++) {
            cout<<arr[i][max_col]<<" ";
        }
        max_col--;
        if(min_row > max_row || min_col > max_col) {
            break;
        }

        // left
        // right to left
        // maxr -> const
        // maxc -> minc
        for(int j = max_col ; j >= min_col ; j--) {
            cout<<arr[max_row][j]<<" ";
        }
        max_row--;
        if(min_row > max_row || min_col > max_col) {
            break;
        }

        // top
        // bottom to top
        // minc -> const
        // maxr -> minr
        for(int i = max_row ; i >= min_row ; i--) {
            cout<<arr[i][min_col]<<" ";
        }
        min_col++;
        if(min_row > max_row || min_col > max_col) {
            break;
        }
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
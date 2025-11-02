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

    cout<<"Both Diagonals of the Matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i == j || i+j == n-1) {
                cout<<arr[i][j]<<" ";
            }
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}

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

// Both Diagonals of the Matrix :
// 1   3
//   5
// 7   9

// Enter rows of matrix : 4
// Enter columns of matrix : 4
// Enter elements of matrix : 
// 1 2 3 4
// 5 6 7 8
// 4 3 2 1
// 8 7 6 5

// matrix : 
// 1 2 3 4 
// 5 6 7 8 
// 4 3 2 1 
// 8 7 6 5 

// Both Diagonals of the Matrix : 
// 1     4 
//   6 7   
//   3 2   
// 8     5 


// Enter rows of matrix : 5
// Enter columns of matrix : 5
// Enter elements of matrix : 
// 1 2 3 4 5
// 5 4 3 2 1
// 1 2 3 4 5
// 5 4 3 2 1
// 1 2 3 4 5

// matrix : 
// 1 2 3 4 5 
// 5 4 3 2 1 
// 1 2 3 4 5 
// 5 4 3 2 1 
// 1 2 3 4 5 

// Both Diagonals of the Matrix : 
// 1       5 
//   4   2   
//     3     
//   4   2   
// 1       5 
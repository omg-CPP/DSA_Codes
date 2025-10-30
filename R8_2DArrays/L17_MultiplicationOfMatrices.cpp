#include <iostream>
using namespace std;
int main()
{
    // matrix 1 : m X n : m rows and n columns
    // matrix 2 : p X q : p rows and q columns

    // Matrix Multiplication is possible if and only if : n == p
    // Resultant Matrix will be of order : m X q

    int m;
    cout<<"Enter rows of first matrix : ";
    cin>>m;
    int n;
    cout<<"Enter columns of first matrix : ";
    cin>>n;

    int p;
    cout<<"Enter rows of second matrix : ";
    cin>>p;
    int q;
    cout<<"Enter columns of second matrix : ";
    cin>>q;

    if(n == p) {

        int arr[m][n];
        cout<<"Enter elements of first matrix : "<<endl;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin>>arr[i][j];
            }
        }

        int brr[p][q];
        cout<<"Enter elements of second matrix : "<<endl;
        for(int i = 0 ; i < p ; i++) {
            for(int j = 0 ; j < q ; j++) {
                cin>>brr[i][j];
            }
        }

        // resultant matrix : order : m X q
        // matrix multiplication
        int res[m][q];
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < q ; j++) {
                res[i][j] = 0;
                for(int k = 0 ; k < n ; k++) {
                    res[i][j] += arr[i][k]*brr[k][j];
                }
            }
        }

        cout<<endl;
        cout<<"Resultant Matrix : "<<endl;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < q ; j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else { // n != p
        cout<<"The Matrices cannot be multiplied"<<endl;
    }
    return 0;
}

// Enter rows of first matrix : 2
// Enter columns of first matrix : 3
// Enter rows of second matrix : 3
// Enter columns of second matrix : 4
// Enter elements of first matrix : 
// 1 2 3
// 4 5 6
// Enter elements of second matrix : 
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12

// Resultant Matrix : 
// 38 44 50 56 
// 83 98 113 128 

// Enter rows of first matrix : 2
// Enter columns of first matrix : 3
// Enter rows of second matrix : 2
// Enter columns of second matrix : 3
// The Matrices cannot be multiplied
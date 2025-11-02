#include <iostream>
using namespace std;
int main()
{
    int A = 0;
    // A -> Sum of numbers of the upper triangle matrix.
    int B = 0;
    // B -> Sum of numbers of the lower triangle matrix.
    int X = 0;
    // X -> Sum of even numbers of odd rows.
    int Y = 0;
    // Y -> Sum of odd numbers of even columns.

    int m;
    cout<<"Enter rows of matrix : ";
    cin>>m;
    int n;
    cout<<"Enter columns of matrix : ";
    cin>>n;

    int matrix[m][n];
    cout<<"Enter elements of the 2D matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<"Enter element arr"<<"["<<i<<"]"<<"["<<j<<"]"<<" : ";
            cin>>matrix[i][j];
        }
    }

    cout<<endl;
    cout<<"2D matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i < j) { 
                // upper triangle matrix
                A = A + matrix[i][j];
                // A -> Sum of numbers of the upper triangle matrix.
            }
            if(i > j) { 
                // lower triangle matrix
                B = B + matrix[i][j];
                // B -> Sum of numbers of the lower triangle matrix.
            }
        }
    }

    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if((i % 2 != 0) && (matrix[i][j] % 2 == 0)) {
                // X -> Sum of even numbers of odd rows.
                X = X + matrix[i][j];
            }
            if((j % 2 == 0) && (matrix[i][j] % 2 != 0)) {
                // Y -> Sum of odd numbers of even columns.
                Y = Y + matrix[i][j];
            }
        }
    }

    cout<<"Sum of all elements of upper triangular matrix : "<<A<<endl;
    cout<<"Sum of all elements of lower triangular matrix : "<<B<<endl;
    cout<<"Sum of all even elements of odd rows : "<<X<<endl;
    cout<<"Sum of all odd elements of even columns : "<<Y<<endl;
    cout<<"Product of A and B is : "<<A*B<<endl;
    cout<<"Difference of X and Y is : "<<X-Y<<endl;
    return 0;
}

// Enter rows of matrix : 3
// Enter columns of matrix : 3
// Enter elements of the 2D matrix : 
// Enter element arr[0][0] : 1
// Enter element arr[0][1] : 2
// Enter element arr[0][2] : 3
// Enter element arr[1][0] : 4
// Enter element arr[1][1] : 5
// Enter element arr[1][2] : 6
// Enter element arr[2][0] : 7
// Enter element arr[2][1] : 8
// Enter element arr[2][2] : 9

// 2D matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 

// Sum of all elements of upper triangular matrix : 11
// Sum of all elements of lower triangular matrix : 19
// Sum of all even elements of odd rows : 10
// Sum of all odd elements of even columns : 20
// Product of A and B is : 209
// Difference of X and Y is : -10
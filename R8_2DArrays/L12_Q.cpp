// Write a program to add two matrices and save the result in one of the given matrices.

#include <iostream>
using namespace std;
// Addition is only possible if m and n of arr are same as m and n of brr i.e. their order must be same.
int main()
{
    int m;
    cout<<"Enter no of rows : ";
    cin>>m;
    int n;
    cout<<"Enter no of columns : ";
    cin>>n;
    int arr[m][n];
    int brr[m][n];

    cout<<"Enter elements of arr : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"arr Matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter elements of brr : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>brr[i][j];
        }
    }
    
    cout<<"brr Matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Storing sum result in arr matrix only
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            arr[i][j] = arr[i][j] + brr[i][j];
        }
    }
    
    cout<<"Resultant Matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 3
// Enter no of columns : 3
// Enter elements of arr : 
// 1 2 3
// 4 5 6
// 7 8 9
// arr Matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 
// Enter elements of brr : 
// 4 5 8
// 0 0 8
// 1 2 0
// brr Matrix : 
// 4 5 8 
// 0 0 8 
// 1 2 0 
// Resultant Matrix : 
// 5 7 11 
// 4 5 14 
// 8 10 9 


// Input 1:
// 1 2 3
// 4 5 6
// 7 8 9

// 4 5 8
// 0 0 8
// 1 2 0

// Output 1:
// 5 7 11
// 4 5 14
// 8 10 9
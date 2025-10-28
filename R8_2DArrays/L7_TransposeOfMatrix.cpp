#include <iostream>
using namespace std;
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

    cout<<endl;

    // printing transpose
    // column wise printing
    for(int j = 0 ; j < n ; j++) {
        for(int i = 0 ; i < m ; i++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int transpose[n][m];
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            transpose[i][j] = arr[j][i];
        }
    }
    // 1 4 
    // 2 5 
    // 3 6 
    cout<<endl;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 4 
    // 2 5 
    // 3 6 
    cout<<endl;
    return 0;
}

// Enter no of rows : 2
// Enter no of columns : 3
// Enter elements of arr : 
// 1 2 3
// 4 5 6
// arr Matrix : 
// 1 2 3 
// 4 5 6 

// 1 4 
// 2 5 
// 3 6 

// 1 4 
// 2 5 
// 3 6 

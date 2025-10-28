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

    cout<<"Enter elements of brr : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>brr[i][j];
        }
    }

    int sum[m][n];
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            sum[i][j] = arr[i][j] + brr[i][j];
        }
    }
    
    cout<<"Resultant Matrix : "<<endl;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 2
// Enter no of columns : 3
// Enter elements of arr : 
// 1 2 3
// 4 5 6
// Enter elements of brr : 
// 7 8 9
// 10 11 12
// Resultant Matrix : 
// 8 10 12 
// 14 16 18 
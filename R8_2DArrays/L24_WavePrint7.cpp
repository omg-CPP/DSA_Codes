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
    cout<<"Wave Print : "<<endl;
    for(int j =  n-1; j >= 0 ; j--) {
        if(j % 2 == 0) {
            for(int i = 0 ; i < m ; i++) {
                cout<<arr[i][j]<<" ";
            }
        }
        else { // j % 2 != 0
            for(int i = n-1 ; i >= 0 ; i--) {
                cout<<arr[i][j]<<" ";
            }
        }
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

// Wave Print : 
// 3 6 9 8 5 2 1 4 7 
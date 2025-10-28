#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows/columns : ";
    cin>>n;
    int arr[n][n];

    cout<<"Enter elements of arr : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"arr Matrix : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i < j) { // To swap only once
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = i+1 ; j < n ; j++) {
    //         int temp = arr[i][j];
    //         arr[i][j] = arr[j][i];
    //         arr[j][i] = temp;
    //     }
    // }

    cout<<"Transformed Matrix : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

// Enter no of rows/columns : 3
// Enter elements of arr : 
// 1 2 3
// 4 5 6
// 7 8 9
// arr Matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 

// Transformed Matrix : 
// 1 4 7 
// 2 5 8 
// 3 6 9 
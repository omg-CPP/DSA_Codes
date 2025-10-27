#include <iostream>
#include <climits>
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

    cout<<"Enter elements of grid : ";
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>arr[i][j];
        }
    }

    int max = INT_MIN;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    cout<<"Maximum element : "<<max<<endl;

    int min = INT_MAX;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(min > arr[i][j]) {
                min = arr[i][j];
            }
        }
    }
    cout<<"Minimum element : "<<min<<endl;

    return 0;
}

// Enter no of rows : 3
// Enter no of columns : 3
// Enter elements of grid : 
// 1 4 2
// 5 9 1
// 3 4 8
// Maximum element : 9
// Minimum element : 1
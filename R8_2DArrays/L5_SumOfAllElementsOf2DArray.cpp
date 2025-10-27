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

    int sum = 0;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            sum = sum + arr[i][j];
        }
    }
    cout<<"Sum : "<<sum<<endl;

    return 0;
}

// Enter no of rows : 3
// Enter no of columns : 3
// Enter elements of grid : 
// 1 2 3
// 4 5 6
// 7 8 9
// Sum : 45
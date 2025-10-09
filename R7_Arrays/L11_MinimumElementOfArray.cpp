#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }

    // int min = arr[0];
    // for(int i = 1 ; i < n ; i++) {
    //     if(min < arr[i]) {
    //         min = arr[i];
    //     }
    // }

    int min = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }
    cout<<"Minimum Element : "<<min<<endl;
    return 0;
}

// Enter size of array : 6
// Enter the elements of the array : 1 8 2 5 9 6
// Minimum Element : 1
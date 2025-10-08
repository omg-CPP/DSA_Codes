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

    // int max = arr[0];
    // for(int i = 1 ; i < n ; i++) {
    //     if(max < arr[i]) {
    //         max = arr[i];
    //     }
    // }

    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    cout<<"Maximum Element : "<<max<<endl;
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 8 2 5
// Maximum Element : 8

// Enter size of array : 5
// Enter the elements of the array : 1 2 36 2 9
// Maximum Element : 36
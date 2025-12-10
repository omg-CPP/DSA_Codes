#include <iostream>
using namespace std;

// arr = {1,2,3,4,5}

bool isSorted(int arr[], int n) {
    // base case
    if(n == 0 || n == 1) {
        return true;
    }
    // condition
    if(arr[n-1] >= arr[n-2]) {
        // recursive call
        isSorted(arr,n-1);
    }
    else {
        return false;
    }
}

int main()
{
    // int arr[] = {1,2,3,4,5};
    // int n = sizeof(arr)/sizeof(arr[0]);

    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }
    if(isSorted(arr,n) == true) {
        cout<<"Array is Sorted"<<endl;
    }
    else {
        cout<<"Array is not Sorted"<<endl;
    }
    return 0;
}

// Enter size of array : 6
// Enter array elements : 1 5 2 3 4 6
// Array is not Sorted

// Enter size of array : 4
// Enter array elements : 6 1 5 8
// Array is not Sorted
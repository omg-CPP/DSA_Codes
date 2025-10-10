#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // Two Pointer Approach
    int i = 0;
    cout<<arr[0]<<" ";  // First Element will always be unique
    for(int j = 1 ; j < n ; j++) {
        if(arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            cout<<arr[i+1]<<" ";
            i++;  // i = 2
        }
    }
    cout<<endl<<"Unique Elements are : "<<i+1<<endl; // i = 3
    // Unique Elements are : 3
    return 0;
}

// 1 2 3 
// Unique Elements are : 3
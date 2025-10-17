#include <iostream>
using namespace std;
int main()
{
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int nge[n];
    nge[n-1] = -1;
    int max = arr[n-1];
    for(int i = n-2 ; i >= 0 ; i--) {
        nge[i] = max;
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 0 1 0 2 1 0 1 3 2 1 2 1 
    cout<<endl;
    for(int i = 0 ; i < n ; i++) {
        cout<<nge[i]<<" ";
    }
    // 3 3 3 3 3 3 3 2 2 2 1 -1 
    cout<<endl;
    return 0;
}

// 0 1 0 2 1 0 1 3 2 1 2 1 
// 3 3 3 3 3 3 3 2 2 2 1 -1 
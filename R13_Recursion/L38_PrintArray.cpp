#include <iostream>
using namespace std;

void display(int arr[], int n) {
    // base case
    if(n == 0) {
        return;
    }
    display(arr,n-1);
    cout<<arr[n-1]<<" ";
    return;
}

int main()
{
    int arr[] = {2,1,6,3,9,0,2,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    // using loops
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 2 1 6 3 9 0 2 7 4 
    cout<<endl;

    for(int i : arr) {
        cout<<i<<" ";
    }
    // 2 1 6 3 9 0 2 7 4 
    cout<<endl;

    for(auto a : arr) {
        cout<<a<<" ";
    }
    // 2 1 6 3 9 0 2 7 4 
    cout<<endl;
    
    // using recursion
    display(arr,n);
    // 2 1 6 3 9 0 2 7 4 
    return 0;
}
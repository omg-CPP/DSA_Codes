#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

// Reverse an array using recursion with two pointers
void reverse(int arr[], int i, int j) {
    if(i < j) {
        swap(arr[i],arr[j]);
        reverse(arr,i+1,j-1);
    }
    return;
}

// reverse an array using recursion with a single pointer
void reverseArrayM2(int arr[], int i, int n) {
    if(i >= n/2) {
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverseArrayM2(arr,i+1,n);
    return;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    printArray(arr,n);
    // 1 2 3 4 5 
    reverse(arr,0,n-1);
    printArray(arr,n);
    // 5 4 3 2 1 

    int a[] = {1,2,3,4,5,6};
    printArray(a,6);
    // 1 2 3 4 5 6 
    reverseArrayM2(a,0,6);
    printArray(a,6);
    // 6 5 4 3 2 1 
    return 0;
}
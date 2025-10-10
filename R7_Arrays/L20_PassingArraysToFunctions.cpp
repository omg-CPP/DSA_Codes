#include <iostream>
using namespace std;

void display(int a[], int n) { // int a[] = int* a
    // a and arr are same arrays
    // a is a pointer that is pointing to first element of arr
    for(int i = 0 ; i <= n-1 ; i++) {
        cout<<a[i]<<" ";
        // 1 4 2 7 4 
    }
    cout<<endl;
    return;
}

void change(int b[], int n) { // int b[] = int* b
    // b and arr are same arrays
    // b is a pointer that is pointing to first element of arr
    b[0] = 100;
    return;
}

int main()
{
    int arr[5] = {1,4,2,7,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    // accessing the elements of array in another function
    // Arrays are pass by reference i.e. passing addresses
    // cout<<arr and cout<<&arr are same (addresses)
    // a and b are pointing to arr only 

    char crr[] = {'a','b','c'};
    float f[] = {'1.3','2.4','3,6'};

    display(arr, size); // 1 4 2 7 4 
    change(arr, size);
    display(arr, size); // 100 4 2 7 4 
    return 0;
}
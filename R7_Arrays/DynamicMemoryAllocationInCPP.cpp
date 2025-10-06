#include <iostream>
using namespace std;
int main()
{
    int a = 10; // stored in the stack
    // memory stored in stack : a = 10

    int* p = new int; // memory allocation in heap
    *p = 10;
    cout<<p<<endl; // 0x1001990
    cout<<*p<<endl; // 10

    // dynamic memory allocation done in heap
    // value is stored in heap whereas the pointer reference p is stored in stack which
    // points to the address where the value is present in the heap.

    // p :: 0x11d1990 => p with 0x11d1990 as the address in stack
    // p is pointing to 200 memory address in the heap where value = 10 is stored.

    delete p;  // de-allocate memory in the heap
    // but still the pointer p in the stack is still pointing to same memory address in the heap with no value, such condition is called as dangling pointer.

    int size;
    cout<<"Enter array size : ";
    cin>>size;
    p = new int[size]; // dynamically allocated memory in the heap at the run-time
    // Now p is pointing to the first index element memory address of the array in the heap.
    // pointer p is still in the stack p :: 0x11d1990 (address of first array element)

    cout<<"Enter array elements : ";
    for(int i = 0 ; i < size ; i++) {
        cin>>p[i];
    }

    cout<<p<<endl;  // 0x11d1990
    cout<<*p<<endl; // 1 :: first element of the array

    // for(int i = 0 ; i < size ; i++) {
    //     cout<<*p<<" ";
    //     p++;
    // }
    // 1 2 3 4 5 

    cout<<endl;


    for(int i = 0 ; i < size ; i++) {
        cout<<p[i]<<" ";
    }

    delete[] p; // again de-allocating memory of the array in the heap

    // again pointer 'p' behaves as a dangling pointer

    // so we make p as null

    p = NULL; // p is removed from the stack
    return 0;
}

// crux is basically that in stack we don't have to de-allocate memory after allcating.
// It happens automatically.

// But in heap we have to do it manually, which if not done leads to memory leak.
// memory leak : when you allocate memory in heap and don't delete it.
// servers never terminate if memory leak happens.


// Enter array size : 5
// Enter array elements : 1 2 3 4 5
// 1 2 3 4 5 
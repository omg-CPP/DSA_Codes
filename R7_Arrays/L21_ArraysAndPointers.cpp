#include <iostream>
using namespace std;
int main()
{
    int arr[] = {4,2,6,1,7};
    int* ptr = arr; // giving address
    // int* ptr = &arr[0];

    cout<<ptr<<endl; // 0x61fef8
    cout<<arr<<endl; // 0x61fef8
    cout<<&arr[0]<<endl; // 0x61fef8

    cout<<ptr[0]<<endl; // 4
    for(int i = 0 ; i <= 4 ; i++) {
        cout<<ptr[i]<<" ";
        // 4 2 6 1 7 
    }

    cout<<endl;

    ptr[0] = 8;
    for(int i = 0 ; i <= 4 ; i++) {
        cout<<ptr[i]<<" ";
        // 8 2 6 1 7 
    }

    cout<<endl;

    *ptr = 5;
    for(int i = 0 ; i <= 4 ; i++) {
        cout<<ptr[i]<<" ";
        // 5 2 6 1 7  
    }

    cout<<endl;

    for(int i = 0 ; i <= 4 ; i++) {
        cout<<*ptr<<" ";
        ptr++;
        // 5 2 6 1 7   
    }

    cout<<endl;

    ptr = arr; // again ptr pointing to first element of arr

    *ptr = 8; // ptr[0] = 8
    ptr++; // ptr pointing to 2nd element
    *ptr = 9; // ptr[1] = 9
    ptr--; // ptr is pointing to 1st element

    for(int i = 0 ; i <= 4 ; i++) {
        cout<<*ptr<<" ";
        ptr++;
        // 8 9 6 1 7   
    }

    cout<<endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int arr[7]; // Declaration

    arr[0] = 7; // Initialisation
    arr[1] = 1;
    arr[2] = 6;
    arr[3] = 3;
    arr[4] = 9;
    arr[5] = 7;
    arr[6] = 0;

    cout<<arr[0]<<" "; 
    cout<<arr[1]<<" "; 
    cout<<arr[2]<<" ";
    cout<<arr[3]<<" ";
    cout<<arr[4]<<" ";
    cout<<arr[5]<<" ";
    cout<<arr[6]<<" ";
    // 7 1 6 3 9 7 0 6

    cout<<endl;

    for(int i = 0 ; i <= 6 ; i++) {
        cout<<arr[i]<<" ";
    }

    // 7 1 6 3 9 7 0 

    cout<<endl;

    int nums[7] = {1,5,9,4,6,3,1};
    cout<<nums[4]<<endl; // 6
    cout<<nums[6]<<endl; // 1


    int a[] = {1,2,3,4};
    cout<<a[2]<<endl; // 3


    // for Taking input and printing output

    int brr[7];
    for(int i = 0 ; i <= 6 ; i++) {
        cin>>arr[i];
    }
    
    // for printing
    for(int i = 0 ; i <= 6 ; i++) {
        cout<<arr[i]<<" ";
    }
    // 5 4 5 6 7 8 9 
    // 5 4 5 6 7 8 9 
    return 0;
}
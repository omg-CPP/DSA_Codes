// Array contains only positive elements
// Array is sorted
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,4,7,9};
    // int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool flag = false;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] != i+1) {
            flag = true;
            cout<<i+1<<" is the smallest missing positive"<<endl;
            break;
        }
    }
    if(flag == false) {
        cout<<"No missing positive element"<<endl;
    }
    return 0;
}

// int arr[] = {1,2,4,7,9};
// 3 is the smallest missing positive

// int arr[] = {1,2,3,4,5};
// No missing positive element
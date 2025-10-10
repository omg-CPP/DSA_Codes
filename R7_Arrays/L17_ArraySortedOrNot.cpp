#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }

    bool flag = true;  // Array is sorted
    for(int i = 1 ; i < n ; i++) {
        if(arr[i] >= arr[i-1]) {
            continue;
        }
        else {
            flag = false;
            break;
        }
    }
    if(flag == true) {
        cout<<"Array is sorted"<<endl;
    }
    else {
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 5
// Array is sorted

// Enter size of array : 5
// Enter the elements of the array : 5 4 3 2 1
// Array is not sorted

// Enter size of array : 5
// Enter the elements of the array : 1 8 5 3 2
// Array is not sorted

// Enter size of array : 5
// Enter the elements of the array : 1 5 8 9 10
// Array is sorted
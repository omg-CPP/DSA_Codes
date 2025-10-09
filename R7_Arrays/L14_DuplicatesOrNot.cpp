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

    bool flag = false; // No duplicates exist
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(arr[i] == arr[j]) {
                flag = true; // duplicates found
                break;
            }
        }
        if(flag == true) {
            break;
        }
    }
    if(flag == true) {
        cout<<"Contains Duplicates"<<endl;
    }
    else {
        cout<<"All Elements are Unique"<<endl;
    }
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 5
// All Elements are Unique

// Enter size of array : 6
// Enter the elements of the array : 1 -3 2 -5 1 6
// Contains Duplicates
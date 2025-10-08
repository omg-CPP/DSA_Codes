#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    int x;
    cout<<"Enter element you want to search : ";
    cin>>x;
    cout<<"Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }

    // linear search
    // check-mark
    bool flag = false;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] == x) {
            flag = true;
            break;
        }
    }
    if(flag == true) {
        cout<<"Element found"<<endl;
    }
    else {
        cout<<"404 : Element not found"<<endl;
    }
    return 0;
}

// Enter size of array : 5
// Enter element you want to search : 7
// Enter the elements of the array : 1 2 3 4 5
// 404 : Element not found

// Enter size of array : 5
// Enter element you want to search : 8
// Enter the elements of the array : 1 8 7 5 4
// Element found
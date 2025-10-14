// change odd index elements to second multiple
// change even index elements by incrementing by 10

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }

    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i < n ; i++) {
        if(i % 2 != 0) {
            arr[i] *= 2;
        }
        else {
            arr[i] += 10;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

// Enter array size : 6
// Enter array elements : 1 2 3 6 5 4
// 1 2 3 6 5 4 
// 11 4 13 12 15 8 
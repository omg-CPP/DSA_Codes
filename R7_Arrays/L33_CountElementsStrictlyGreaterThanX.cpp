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

    int x;
    cout<<"Enter x : ";
    cin>>x;

    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] > x) {
            count++;
        }
    }
    cout<<"Number of Elements Greater than "<<x<<" are : "<<count<<endl;
    return 0;
}

// Enter array size : 6
// Enter array elements : 5 2 1 7 3 9
// Enter x : 4
// Number of Elements Greater than 4 are : 3
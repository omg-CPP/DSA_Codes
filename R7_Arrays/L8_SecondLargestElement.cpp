#include <iostream>
#include <climits>
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

    // finding largest
    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    cout<<"Largest Element : "<<max<<endl;

    // finding second largest
    int smax = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        if(smax < arr[i] && arr[i] != max) {
            smax = arr[i];
        }
    }
    cout<<"Second Largest Element : "<<smax<<endl;
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 5
// Largest Element : 5
// Second Largest Element : 4

// Enter size of array : 5
// Enter the elements of the array : 32 45 56 21 98
// Largest Element : 98
// Second Largest Element : 56

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 4
// Largest Element : 4
// Second Largest Element : 3
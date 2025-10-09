#include <iostream>
#include <climits>
#include <math.h>
#include <cmath>
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

    // finding smallest
    int min = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
        // in-built functions can also be used : min
        // mini = min(mini,arr[i]);
    }
    cout<<"Smallest Element : "<<min<<endl;

    // finding second smallest
    int smin = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        if(smin > arr[i] && arr[i] != min) {
            smin = arr[i];
        }
    }
    cout<<"Second Smallest Element : "<<smin<<endl;
    return 0;
}

// Enter size of array : 6
// Enter the elements of the array : 4 2 5 8 6 7
// Smallest Element : 2
// Second Smallest Element : 4
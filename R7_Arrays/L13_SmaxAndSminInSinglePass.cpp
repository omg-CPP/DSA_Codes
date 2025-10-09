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

    // finding largest and second largest in one pass
    int mx = INT_MIN;
    int smx = INT_MIN;

    for(int i = 0 ; i < n ; i++) {
        if(mx < arr[i]) {
            smx = mx;
            mx = arr[i];
        }
        else if(mx > arr[i] && arr[i] > smx) {
            smx = arr[i];
        }
    }

    cout<<"Largest Element : "<<mx<<endl;
    if(smx == INT_MIN) {
        cout<<"No Second Largest Element Exist"<<endl;
    }
    else {
        cout<<"Second Largest Element : "<<smx<<endl;
    }

    // finding smallest and second smallest in one pass
    int mi = INT_MAX;
    int smi = INT_MAX;

    for(int i = 0 ; i < n ; i++) {
        if(mi > arr[i]) {
            smi = mi;
            mi = arr[i];
        }
        else if(mi < arr[i] && arr[i] < smi) {
            smi = arr[i];
        }
    }

    cout<<"Smallest Element : "<<mi<<endl;
    if(smi == INT_MAX) {
        cout<<"No Second Smallest Element Exist"<<endl;
    }
    else {
        cout<<"Second Smallest Element : "<<smi<<endl;
    }
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 5
// Largest Element : 5
// Second Largest Element : 4
// Smallest Element : 1
// Second Smallest Element : 2

// Enter size of array : 5
// Enter the elements of the array : 2 1 1 1 10
// Largest Element : 10
// Second Largest Element : 2
// Smallest Element : 1
// Second Smallest Element : 2

// Enter size of array : 5    
// Enter the elements of the array : 2 1 1 1 1
// Largest Element : 2
// Second Largest Element : 1
// Smallest Element : 1
// Second Smallest Element : 2

// Enter size of array : 5
// Enter the elements of the array : 1 1 1 1 1
// Largest Element : 1
// No Second Largest Element Exist
// Smallest Element : 1
// No Second Smallest Element Exist

// Enter size of array : 5
// Enter the elements of the array : 2 3 7 7 5
// Largest Element : 7
// Second Largest Element : 5
// Smallest Element : 2
// Second Smallest Element : 3

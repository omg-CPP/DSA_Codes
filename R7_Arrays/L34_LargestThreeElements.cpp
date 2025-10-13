#include <iostream>
#include <climits>
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

    int mx = INT_MIN;
    int smx = INT_MIN;
    int tmx = INT_MIN;

    // Single Pass Solution

    for(int i = 0 ; i < n ; i++) {
        if(mx < arr[i]) {
            tmx = smx;
            smx = mx;
            mx = arr[i];
        }
        else if(mx > arr[i] && arr[i] > smx) {
            smx = arr[i];
        }
        else if(smx > arr[i] && arr[i] > tmx) {
            tmx = arr[i];
        }
    }

    cout<<"Max : "<<mx<<endl;

    if(smx == INT_MIN) {
        cout<<"Second max doesn't exist"<<endl;
    }

    else {
        cout<<"Second Max : "<<smx<<endl;
    }
    if(tmx == INT_MIN) {
        cout<<"Third max doesn't exist"<<endl;
    }
    else {
        cout<<"Third Max : "<<tmx<<endl;
    }
    return 0;
}

// Enter array size : 5
// Enter array elements : 1 2 2 2 2
// Max : 2
// Second Max : 1
// Third max doesn't exist

// Enter array size : 4
// Enter array elements : 1 1 1 1
// Max : 1
// Second max doesn't exist
// Third max doesn't exist

// Enter array size : 6   
// Enter array elements : 1 2 2 2 3 4
// Max : 4
// Second Max : 3
// Third Max : 2

// Enter array size : 5        
// Enter array elements : 1 2 2 2 4
// Max : 4
// Second Max : 2
// Third Max : 1
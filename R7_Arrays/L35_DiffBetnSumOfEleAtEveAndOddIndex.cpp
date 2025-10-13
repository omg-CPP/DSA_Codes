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

    int sumEven = 0;
    int sumOdd = 0;
    for(int i = 0 ; i < n ; i++) {
        if(i % 2 == 0) {
            sumEven += arr[i];
        }
        else {
            sumOdd += arr[i];
        }
    }
    cout<<sumEven-sumOdd<<endl;
    return 0;
}

// Enter array size : 6
// Enter array elements : 1 2 3 7 6 5
// -4

// sumEven = 1 + 3 + 6 = 10
// sumOdd = 2 + 7 + 5 = 14
// diff = -4
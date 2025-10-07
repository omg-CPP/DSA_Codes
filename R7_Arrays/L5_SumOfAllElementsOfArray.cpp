#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    // input
    cout<<"Enter the elements of the array : ";
    for(int i = 0 ; i <= n-1 ; i++) {
        cin>>arr[i];
    }
    int sum = 0;
    for(int i = 0 ; i <= n-1 ; i++) {
        sum = sum + arr[i];
    }
    cout<<"Sum : "<<sum<<endl;
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 5
// Sum : 15
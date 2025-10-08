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
    int product = 1;
    for(int i = 0 ; i <= n-1 ; i++) {
        product = product * arr[i];
    }
    cout<<"product : "<<product<<endl;
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 1 2 3 4 5
// product : 120

// Enter size of array : 5
// Enter the elements of the array : 2 5 6 8 3
// product : 1440
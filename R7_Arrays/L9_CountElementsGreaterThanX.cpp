#include <iostream>
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

    int x;
    cout<<"Enter X : ";
    cin>>x;
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] > x) {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}

// Enter size of array : 5
// Enter the elements of the array : 34 45 12 18 95
// Enter X : 50
// 1

// Enter size of array : 5
// Enter the elements of the array : 45 12 36 28 73
// Enter X : 20
// 4
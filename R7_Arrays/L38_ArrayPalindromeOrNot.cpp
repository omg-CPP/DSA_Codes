#include <iostream>
using namespace std;
int main()
{
    // if reverse of array is same as array
    // Then palindrome
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }

    bool flag = true; // means palindrome
    int i = 0; 
    int j = n-1;
    while(i <= j) {
        if(arr[i] != arr[j]) {
            flag = false;
            break;
        }
        i++;
        j--;
    }
    if(flag == true) {
        cout<<"Palindrome Array"<<endl;
    }
    else {
        cout<<"Not a Palindrome Array"<<endl;
    }
    return 0;
}

// Enter array size : 9
// Enter array elements : 1 2 1 4 2 3 4 5 5 
// Not a Palindrome Array

// Enter array size : 6
// Enter array elements : 1 2 3 3 2 1
// Palindrome Array

// Enter array size : 5
// Enter array elements : 1 2 3 2 1
// Palindrome Array
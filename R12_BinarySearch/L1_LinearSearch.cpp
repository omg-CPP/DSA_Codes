#include <iostream>
using namespace std;

// Time Complexity : O(n)
// Linear Search : Linear Time Complexity
// No of Operations : n
bool linearSearch(int arr[], int n, int target) {
    bool flag = false; // element not present
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] == target) {
            flag = true; // element found
            return flag;
        }
    }
    return flag;
}

int main()
{
    int arr[] = {1,2,4,5,9,15,18,21};
    // Search Space
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout<<"Enter element to be searched : ";
    cin>>target;
    if(linearSearch(arr,n,target) == true) {
        cout<<target<<" is present"<<endl;
    }
    else {
        cout<<target<<" is not present"<<endl;
    }
    return 0;
}

// Enter element to be searched : 18
// 18 is present

// Enter element to be searched : 12
// 12 is not present
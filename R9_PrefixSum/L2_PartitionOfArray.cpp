#include <iostream>
using namespace std;
// Check if the array can be partitionised into two continuous
// arrays of equal sum
int main()
{
    int arr[] = {1,2,3,4,5,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    // print
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 1 2 3 4 5 5 10 
    cout<<endl;

    // formation of prefix sum array
    for(int i = 1 ; i < n ; i++) {
        arr[i] = arr[i] + arr[i-1];
    }
    // print
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 1 3 6 10 15 20 30 
    cout<<endl;

    // check if any x exist or not
    // explanation : 
    // arr = {1,2,3,4,5,5,10}
    // prefix-arr = {1,3,6,10,15,20,30}
    // x -> index
    // 0 to x tak ka sum == x+1 to n-1 tak ka sum
    // 0 to x tak ka sum = prefix-arr[x]
    // x+1 to n-1 tak ka sum = prefix-arr[n-1] - prefix-arr[(x+1)-1]
    // prefix-arr[x] = prefix-arr[n-1] - prefix-arr[(x+1)-1]
    // prefix-arr[x] = prefix-arr[n-1] - prefix-arr[x]
    // prefix-arr[x] + prefix-arr[x] = prefix-arr[n-1] 
    // 2*prefix-arr[x] = prefix-arr[n-1] 
    // 0 to i tak ka sum == i+1 to n-1 tak ka sum
    // check for a condition : if(2*arr[i] == arr[n-1])

    int idx = -1;
    for(int i = 0 ; i < n ; i++) {
        if(2*arr[i] == arr[n-1]) {
            idx = i;
            break;
        }
    }

    if(idx != -1) {
        cout<<"Yes, array can be partitioned after index "<<idx<<endl;
    }
    else { // idx == -1
        cout<<"Sorry, array cannot be partitioned"<<endl;
    }
    return 0;
}

// Yes, array can be partitioned after index 4
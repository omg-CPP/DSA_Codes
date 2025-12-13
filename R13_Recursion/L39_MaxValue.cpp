#include <iostream>
#include <climits>
using namespace std;

void printMax(int arr[], int n, int max) {
    // max kept on updating
    // base case
    if(n == 0) {
        cout<<max<<endl;
        return;
    }
    if(max < arr[n-1]) {
        max = arr[n-1];
    }
    printMax(arr,n-1,max);
    return;
}

int maximumValue(int arr[], int n) {
    if(n == 1) {
        return arr[n-1];
    }
    return max(arr[n-1],maximumValue(arr,n-1));
}

int main()
{
    int arr[] = {2,1,6,3,9,0,2,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = INT_MIN;
    printMax(arr,n,max); // 9

    cout<<endl;

    int mx = maximumValue(arr,n);
    cout<<mx<<endl; // 9
    return 0;
}
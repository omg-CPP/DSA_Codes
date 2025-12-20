#include <iostream>
#include <climits>
using namespace std;

int minimumValue(int arr[], int n, int min) {
    if(n == 0) {
        return min;
    }
    if(min > arr[n-1]) {
        min = arr[n-1];
    }
    return minimumValue(arr,n-1,min);
}
int main()
{
    int arr[] = {2,3,7,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int min = INT_MAX;
    int ans = minimumValue(arr,n,min);
    cout<<ans<<endl; // 2
    return 0;
}
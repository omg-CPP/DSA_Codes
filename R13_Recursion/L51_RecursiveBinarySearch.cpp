#include <iostream>
using namespace std;

// T.C. : O(logn)
// S.C. : O(logn)
int recursiveBinarySearch(int arr[], int target, int i, int j) {
    // arr = {-1,0,3,5,9,12}
    // target = 5
    // 1 -> -1,0,3,5,9,12 : arr[mid] = 3
    // 2 -> 5,9,12 : arr[mid] = 9
    // 3 -> 5 : i,j both points to 5, therefore arr[mid] points to 5
    while(i <= j) {
        int mid = i + (j-i)/2;
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] < target) {   // first half removed
            // ans present in second half
            // recursive call
            int ans = recursiveBinarySearch(arr,target,mid+1,j);
            return ans;
        }
        else { // (arr[mid] > target)  // second half removed
            // ans present in first half
            // recursive call
            int ans = recursiveBinarySearch(arr,target,i,mid-1);
            return ans;
        }
    }
    return -1; // If target value does not exist
}
int main()
{
    int arr[] = {-1,0,3,5,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    int idx = recursiveBinarySearch(arr,target,0,n-1);
    cout<<target<<" is present at index : "<<idx<<endl;
    // 5 is present at index : 3
    return 0;
}
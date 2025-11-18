// Quick Sort Algorithm
// Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order.

// steps : Pick a pivot and place it in it's correct position in the sorted array.
// Smaller on the left and larger on the right.

// pivot : 
// 1st element of the array
// last element of the array
// median of the array
// any random element of the array


// pivot : first element of the array


#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while(i < n) {
        cout<<nums[i]<<" ";
        i++;
    }
    cout<<endl;
}

int partition(vector<int>& arr, int lo, int hi) {
    int pivot = arr[lo];
    int i = lo;
    int j = hi;
    while(i < j) {
        while(arr[i] <= pivot && i <= hi-1) {
            i++;
        }
        while(arr[j] > pivot && j >= lo+1) {
            j--;
        }
        if(i < j) {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[lo],arr[j]);
    return j;
}

void qS(vector<int>& arr, int lo, int hi) {
    int n = arr.size();
    if(lo < hi) {
        int pivotIdx = partition(arr,lo,hi);
        qS(arr,lo,pivotIdx-1);
        qS(arr,pivotIdx+1,hi);
    }
}

void quickSort(vector<int>& arr) {
    int n = arr.size();
    qS(arr,0,n-1);
}

int main()
{
    vector<int> arr = {4,6,2,5,7,9,1,3};
    printArray(arr); // 4 6 2 5 7 9 1 3 
    quickSort(arr);
    printArray(arr); // 1 2 3 4 5 6 7 9 
    return 0;
}
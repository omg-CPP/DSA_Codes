// Merge Sort Algorithm : Divide and Merge
// Recursion and Backtracking

// arr = {3,1,2,4,1,5,2,6,4}
// Dividing the arr into 5 and 4 sets

//     {3,1,2,4,1}           {5,2,6,4}
//   {3,1,2}    {4,1}      {5,2}   {6,4}
//  {3,1} {2}  {4} {1}    {5} {2} {6} {4}
// {3} {1}

// Than merge the two sorted arrays to get result

// Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.

// Time Complexity of Merge Sort Algorithm



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

void merge(vector<int>& arr, int lo, int mid, int hi) {
    vector<int> temp;

    // first arr = [lo...mid]
    // second arr = [mid+1...hi]
    int left = lo;
    int right = mid+1;

    while(left <= mid && right <= hi) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else { // arr[left] > arr[right]
            temp.push_back(arr[right]);
            right++;
        }
    }

    if(left == mid+1) {
        while(right <= hi) {
            temp.push_back(arr[right]);
            right++;
        }
    }

    if(right == hi+1) {
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    }

    for(int i = lo ; i <= hi ; i++) {
        arr[i] = temp[i-lo];
    }
}

void mS(vector<int>& arr, int lo, int hi) {
    int n = arr.size();
    if(lo == hi) {
        return;
    }
    int mid = (lo + hi) / 2;
    mS(arr,lo,mid);
    mS(arr,mid+1,hi);
    merge(arr,lo,mid,hi);
}

// T.C. = O(nlogn)
// S.C. = O(n)
void mergeSort(vector<int>& arr) {
    int n = arr.size();
    mS(arr,0,n-1);
}

int main()
{
    vector<int> arr = {3,1,2,4,1,5,2,6,4};
    int n = arr.size();
    printArray(arr); // 3 1 2 4 1 5 2 6 4 
    mergeSort(arr);
    printArray(arr); // 1 1 2 2 3 4 4 5 6 
    return 0;
}
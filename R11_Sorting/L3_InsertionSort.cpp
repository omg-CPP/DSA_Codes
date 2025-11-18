// Insertion Sort : Takes an element and places it in it's correct postion or order

// arr = {14,9,15,12,6,8,13}

// arr = {9,14,15,12,6,8,13}

// arr = {9,14,15,12,6,8,13}

// arr = {9,14,15,12,6,8,13}
// arr = {9,14,12,15,6,8,13}
// arr = {9,12,14,15,6,8,13}

// arr = {9,12,14,15,6,8,13}
// arr = {9,12,14,6,15,8,13}
// arr = {9,12,6,14,15,8,13}
// arr = {9,6,12,14,15,8,13}
// arr = {6,9,12,14,15,8,13}

// arr = {6,9,12,14,15,8,13}
// arr = {6,9,12,14,8,15,13}
// arr = {6,9,12,8,14,15,13}
// arr = {6,9,8,12,14,15,13}
// arr = {6,8,9,12,14,15,13}

// arr = {6,8,9,12,14,15,13}
// arr = {6,8,9,12,14,13,15}
// arr = {6,8,9,12,13,14,15}

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

// arr = {5,4,3,2,1}
// operations = 1 + 2 + 3 + 4
// again Total operations = [(n-1) * (n)] / 2 
// Worst Case and Avg Case : O(n^2)
// arr = {1,2,3,4,5}
// Best Case : O(n-1) = O(n)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1 ; i < n ; i++) { // n-1 times
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    vector<int> nums = {13,46,24,52,20,9};
    printArray(nums); // 13 46 24 52 20 9 
    insertionSort(nums);
    printArray(nums); // 9 13 20 24 46 52
    return 0;
}
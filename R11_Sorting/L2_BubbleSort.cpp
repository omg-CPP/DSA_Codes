// Bubble Sort : push the maximum to the last by adjacent swaps

// arr = {13,46,24,52,20,9}
// step 1 : 5 inner steps
// arr = {13,46,24,52,20,9}
// arr = {13,24,46,52,20,9}
// arr = {13,24,46,52,20,9}
// arr = {13,24,46,20,52,9}
// arr = {13,24,46,20,9,52}


// arr = {13,24,46,20,9,52}
// step 2 : 4 inner steps : leaving last element
// arr = {13,24,46,20,9,52}
// arr = {13,24,46,20,9,52}
// arr = {13,24,20,46,9,52}
// arr = {13,24,20,9,46,52}

// arr = {13,24,20,9,46,52}
// step 3 : 3 inner steps : leaving last 2 elements

// arr = {13,24,20,9,46,52}
// arr = {13,20,24,9,46,52}
// arr = {13,20,9,24,46,52}

// arr = {13,20,9,24,46,52}
// step 4 : 2 inner steps : leaving last 3 elements

// arr = {13,20,9,24,46,52}
// arr = {13,9,20,24,46,52}

// arr = {13,9,20,24,46,52}
// step 5 : 1 inner steps : leaving last 4 elements

//  arr = {9,13,20,24,46,52}


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

// T.C. = i = n-1 :: j = 0 to n-2 :: n-1 times
//        i = n-2 :: j = 0 to n-3 :: n-2 times
//        i = 1   :: j = 0 to 0   :: 1 time

// T.C. = 1 + 2 + 3 + ----------------- + n-2 + n-1
// Total operations = [(n-1) * (n)] / 2 
// Worst Case : O(n^2)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = n-1 ; i >= 1 ; i--) { // n-1 times
        for(int j = 0 ; j <= i-1 ; j++) { 
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// If array is already sorted 
// arr = {1,2,3,4,5}
// Total Operations = n-1
// Best Case T.C. = O(n-1) = O(n)
void bubbleSortOptimised(vector<int>& arr) {
    int n = arr.size();
    bool flag = true;
    for(int i = n-1 ; i >= 1 ; i--) { // n-1 times
        for(int j = 0 ; j <= i-1 ; j++) { 
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = false;
            }
        }
        if(flag == true) {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {13,46,24,52,20,9};
    printArray(nums); // 13 46 24 52 20 9 
    bubbleSort(nums);
    printArray(nums); // 9 13 20 24 46 52
    return 0;
}
// Selection Sort 
// step 1 : select minimums and swap

// arr = {13,46,24,52,20,9}
// min = 13
// arr = {9,46,24,52,20,13}
// min = 13
// arr = {9,13,24,52,20,46}
// min = 20
// arr = {9,13,20,52,24,46}
// min = 24
// arr = {9,13,20,24,52,46}
// min = 46
// arr = {9,13,20,24,46,52}

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
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

void swapTwoNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// T.C. => i = 0 :: j = 0 to n-1  ::  n
//         i = 1 :: j = 1 to n-1  ::  n-1
//         i = 2 :: j = 2 to n-1  ::  n-2


//         i = n-2 :: j = n-2 to n-1 :: 2

// Total operations = 2 + 3 + 4 + ----- + n
// [n(n+1) / 2] - 1 
// O(n^2)

void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0 ; i < n-1 ; i++) {    // n-2 operations
        int mini = i;
        // finding minimum in the next elements
        for(int j = i+1 ; j < n ; j++) {  // n
            if(nums[j] < nums[mini]) {
                mini = j;
            }
        }
        // option 1
        // int temp = nums[i];
        // nums[i] = nums[mini];
        // nums[mini] = temp;

        // option 2
        swap(nums[i],nums[mini]);

        // option 3
        // swapTwoNumbers(&nums[i],&nums[mini]);
    }
}

int main() {
    vector<int> nums = {13,46,24,52,20,9};
    printArray(nums); // 13 46 24 52 20 9 
    selectionSort(nums);
    printArray(nums); // 9 13 20 24 46 52
}
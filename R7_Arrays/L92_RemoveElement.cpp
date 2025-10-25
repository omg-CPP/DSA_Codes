// Leetcode : 27
// Return the first k elements which are not equal to val, rest array doesn't matter,
// also we need to mofify the same array.

#include <iostream>
#include <vector>
using namespace std;

// Similar to Move Zeros to End of the Array
// T.C. = O(n)
// S.C. = O(1)
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int j = -1;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == val) {
            j = i;
            break;
        }
    }
    if(j == -1) {
        return n;
    }
    for(int i = j+1 ; i < n ; i++) {
        if(nums[i] != val) {
            swap(nums[i],nums[j]);
            j++;
        }
    }
    return j;
}

int main()
{
    return 0;
}
// Leetcode : 80

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) { // base case
        return n;
    }
    int i = 0;
    for(int i = 2 ; i < n ; i++) {
        if(nums[i] != nums[i-2]) {
            nums[i] = 
            i++;
        }
    }
}

int main()
{
    return 0;
}
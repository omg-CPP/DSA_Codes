// Leetcode : 26

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(1)
int removeDuplicates(vector<int>& nums) {
    // Two Pointers
    int n = nums.size();
    int i = 0;
    for(int j = i+1 ; j < n ; j++) {
        if(nums[i] != nums[j]) {
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 0 0 1 1 1 2 2 3 3 4 
    cout<<endl;
    cout<<removeDuplicates(nums)<<endl; // 5
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 0 1 2 3 4 2 2 3 3 4
    cout<<endl;
    return 0;
}
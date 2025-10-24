// Leetcode : 2221

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n^2)
// S.C. = O(n^2)
int triangularSumBruteForce(vector<int>& nums) {
    while(nums.size() > 1) {
        vector<int> newNums;
        for(int i = 0 ; i < nums.size()-1 ; i++) {
            newNums.push_back((nums[i]+nums[i+1])%10);
        }
        nums = newNums; // deep copy : new copy is generated
    }
    return nums[0];
}

// T.C. = O(n^2)
// S.C. = O(1)
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0 ; i < n-1 ; i++) {
        for(int j = 0 ; j < n-1 ; j++) {
            nums[j] = (nums[j] + nums[j+1]) % 10;
        }
    }
    return nums[0];
}

// arr    : {1,2,3,4,5}
// step 1 : {3,5,7,9,5}
// step 2 : {8,2,6,4,5}
// step 3 : {0,8,0,9,5}
// step 4 : {8,8,9,4,5}
// return nums[0] = 8 after n-1 steps

int main()
{
    return 0;
}

// eg : 
// arr = {1,2,3,4,5}
//        {3,5,7,9}
//         {8,2,6}
//          {0,8}
//           {8}
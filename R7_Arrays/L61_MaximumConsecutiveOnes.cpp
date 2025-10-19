#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n) since the solution involves only a single pass.

// Space Complexity: O(1) because no extra space is used.
int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;
    int cnt = 0;
    for(int i = 0 ; i < nums.size() ; i++) {
        if(nums[i] == 1) {
            cnt++;
            maxi = max(maxi,cnt);
        }
        else {
            cnt = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {1,1,0,1,1,1};
    int ans = findMaxConsecutiveOnes(nums);
    cout<<"The maximum consecutive 1's are : "<<ans;
    // The maximum consecutive 1's are : 3
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// input Array given is already sorted
// So we apply two pointers
// Time Complexity : O(n)
// Space Complexity : O(1) : as we are not using any extra space

// if array is not been sorted, we sort the array then the order of elements get changed
// And we will not be able to return the original indexes of elements that sum upto the target value
// But we can return the elements though
// Time Complexity : O(nlogn + n) = O(nlogn)
// Space Complexity : O(1) : as we are not using any extra space

vector<int> twoSumII(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int i = 0;
    int j = n-1;
    while(i < j) {
        int sum = nums[i] + nums[j];
        if(sum == target) {
            ans.push_back(i+1);
            ans.push_back(j+1);
            return ans;
        }
        else if(sum < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSumII(arr,target);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 2 
    cout<<endl;
    return 0;
}
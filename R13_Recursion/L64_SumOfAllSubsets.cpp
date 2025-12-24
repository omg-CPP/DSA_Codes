#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

// Space Complexity : O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

void helper(int idx, vector<int>& arr, vector<int>& ans, int sum) {
    int n = arr.size();
    // base case
    if(idx == n) {
        ans.push_back(sum);
        return;
    }
    // left call : Not added
    helper(idx+1,arr,ans,sum);
    // right call : added
    helper(idx+1,arr,ans,sum+arr[idx]);
}

vector<int> subsetSum(vector<int> arr) {
    vector<int> ans;
    helper(0,arr,ans,0);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {3,1,2};
    vector<int> ans = subsetSum(arr);
    // sort(ans.begin(),ans.end());
    cout<<"The sum of each subset is : ";
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // The sum of each subset is : 0 1 2 3 3 4 5 6 
    cout<<endl;

    vector<int> nums = {5,2,1};
    vector<int> res = subsetSum(nums);
    // sort(ans.begin(),ans.end());
    cout<<"The sum of each subset is : ";
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    // The sum of each subset is : 0 1 2 3 5 6 7 8 
    cout<<endl;
    return 0;
}

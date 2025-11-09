#include <iostream>
#include <vector>
using namespace std;


vector<long long> findPrefixScore(vector<int>& nums) {
    int n = nums.size();
    vector<long long> prefix(n);
    prefix[0] = nums[0];
    // Creating a max array
    for(int i = 1 ; i < n ; i++) {
        prefix[i] = max(prefix[i-1],(long long)nums[i]);
    }
    // Creating a cover array
    for(int i = 0 ; i < n ; i++) {
        prefix[i] = prefix[i] + nums[i];
    }
    // Creating a score array
    for(int i = 1 ; i < n ; i++) {
        prefix[i] = prefix[i-1] + prefix[i];
    }
    return prefix;
}


int main()
{
    vector<int> arr = {2,3,7,5,10};
    vector<long long> ans = findPrefixScore(arr);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 4 10 24 36 56 
    cout<<endl;
    return 0;
}
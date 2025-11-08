#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelfBruteForce(vector<int>& nums) {
    int n = nums.size();
    int prod1 = 1;
    int prod2 = 1;
    int noOfZeros = 0;
    for(int i = 0 ; i < n ; i++) {
        prod1 = prod1 * nums[i];
        if(nums[i] != 0) {
            prod2 = prod2 * nums[i];
        }
        if(nums[i] == 0) {
            noOfZeros++;
        }
    }
    if(noOfZeros > 1) {
        prod2 = 0;
    }
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == 0) {
            nums[i] = prod2;
        }
        else { // nums[i] != 0
            nums[i] = prod1/nums[i];
        }
    }
    return nums;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    // vector<int> ans(n);

    // prefix product array creation
    int p = nums[0];
    prefix[0] = 1;
    for(int i = 1 ; i < n ; i++) {
        prefix[i] = p;
        p = p * nums[i];
    }

    // suffix product array creation
    int s = nums[n-1];
    suffix[n-1] = 1;
    for(int i = n-2 ; i >= 0 ; i--) {
        suffix[i] = s;
        s = s * nums[i];
    }

    // for(int i = 0 ; i < n ; i++) {
    //     ans[i] = prefix[i] * suffix[i];
    // }
    // return ans;

    for(int i = 0 ; i < n ; i++) {
        prefix[i] = prefix[i] * suffix[i];
    }

    return prefix;

}

vector<int> productExceptSelfOptimal(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    // prefix product array creation
    int p = nums[0];
    prefix[0] = 1;
    for(int i = 1 ; i < n ; i++) {
        prefix[i] = p;
        p = p * nums[i];
    }
    // suffix product array creation in prefix only
    p = nums[n-1];
    for(int i = n-2 ; i >= 0 ; i--) {
        prefix[i] = prefix[i] * p;
        p = p * nums[i];
    }
    return prefix;
}
int main()
{

    vector<int> v1 = {1,2,3,4,5};
    vector<int> ans1 = productExceptSelfOptimal(v1);
    for(int i = 0 ; i < ans1.size() ; i++) {
        cout<<ans1[i]<<" ";
    }
    // 120 60 40 30 24 
    cout<<endl;


    // vector<int> v1 = {1,2,3,4,5};
    // vector<int> ans1 = productExceptSelf(v1);
    // for(int i = 0 ; i < ans1.size() ; i++) {
    //     cout<<ans1[i]<<" ";
    // }
    // // 120 60 40 30 24 
    // cout<<endl;

    // vector<int> v2 = {1,2,0,4,5};
    // vector<int> ans2 = productExceptSelf(v2);
    // for(int i = 0 ; i < ans2.size() ; i++) {
    //     cout<<ans2[i]<<" ";
    // }
    // // 0 0 40 0 0 
    // cout<<endl;

    // vector<int> v3 = {1,2,0,4,0};
    // vector<int> ans3 = productExceptSelf(v3);
    // for(int i = 0 ; i < ans3.size() ; i++) {
    //     cout<<ans3[i]<<" ";
    // }
    // // 0 0 0 0 0 
    // cout<<endl;


    // vector<int> v1 = {1,2,3,4,5};
    // vector<int> ans1 = productExceptSelfBruteForce(v1);
    // for(int i = 0 ; i < ans1.size() ; i++) {
    //     cout<<ans1[i]<<" ";
    // }
    // // 120 60 40 30 24 
    // cout<<endl;

    // vector<int> v2 = {1,2,0,4,5};
    // vector<int> ans2 = productExceptSelfBruteForce(v2);
    // for(int i = 0 ; i < ans2.size() ; i++) {
    //     cout<<ans2[i]<<" ";
    // }
    // // 0 0 40 0 0 
    // cout<<endl;

    // vector<int> v3 = {1,2,0,4,0};
    // vector<int> ans3 = productExceptSelfBruteForce(v3);
    // for(int i = 0 ; i < ans3.size() ; i++) {
    //     cout<<ans3[i]<<" ";
    // }
    // // 0 0 0 0 0 
    // cout<<endl;

    return 0;
}
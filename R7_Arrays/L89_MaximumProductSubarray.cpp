// Leetcode : 152

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// T.C. = O(n^3)
// S.C. = O(1)
int maxProductNaive(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j++) {
            int prod = 1;
            for(int k = i ; k <= j ; k++) {
                prod *= nums[k];
            }
            maxProd = max(maxProd,prod);
        }
    }
    return maxProd;
}

// T.C. = O(n^2)
// S.C. = O(1)
int maxProductBetter(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int prod = 1;
        for(int j = i ; j < n ; j++) {
            prod *= nums[j];
            maxProd = max(maxProd,prod);
        }
    }
    return maxProd;
}


// T.C. = O(n)
// S.C. = O(1)
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;
    int pre = 1;
    int suff = 1;
    for(int i = 0 ; i < n ; i++) {
        if(pre == 0) {
            pre = 1;
        }
        if(suff == 0) {
            suff = 1;
        }
        pre = pre * nums[i];
        suff = suff * nums[n-i-1];
        maxProd = max(maxProd,max(pre,suff));
    }
    return maxProd;
}


int main()
{
    vector<int> arr = {1,2,-3,0,-4,-5};
    cout<<maxProductNaive(arr)<<endl; // 20
    cout<<maxProductBetter(arr)<<endl; // 20
    cout<<maxProduct(arr)<<endl; // 20

    vector<int> nums {3,2,-1,4,-6,3,-2,6};
    cout<<maxProductNaive(nums)<<endl; // 864
    cout<<maxProductBetter(nums)<<endl; // 864
    cout<<maxProduct(nums)<<endl; // 864

    vector<int> brr = {-2,3,4,-1,0,-2,3,1,4,0,4,6,-1,4};
    cout<<maxProductNaive(brr)<<endl; // 24
    cout<<maxProductBetter(brr)<<endl; // 24
    cout<<maxProduct(brr)<<endl; // 24
    return 0;
}
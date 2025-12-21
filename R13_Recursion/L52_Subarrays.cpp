#include <iostream>
#include <vector>
using namespace std;
// Work for unique elements only
void subArray(vector<int> v, vector<int>& nums, int idx) {
    int n = nums.size();
    // base case
    if(idx == n) {
        for(int i = 0 ; i < v.size() ; i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(v.size() == 0) { // empty array
        // left call
        subArray(v,nums,idx+1);
        v.push_back(nums[idx]);
        // right call
        subArray(v,nums,idx+1);
    }
    else {
        // left call
        subArray(v,nums,idx+1);
        if(nums[idx-1] == v[v.size()-1]) {
            v.push_back(nums[idx]);
            // right call
            subArray(v,nums,idx+1);
        }
    }
}

int main()
{
    // int arr[] = {1,2,3,4};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // Brute Force
    // for(int i = 0 ; i < n ; i++) { // start of subarray
    //     for(int j = i ; j < n ; j++) { // no of rounds
    //         for(int k = i ; k <= j ; k++) { // range
    //             cout<<arr[k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }


    vector<int> nums = {1,2,3,4};
    vector<int> v;
    subArray(v,nums,0);
    return 0;
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 2 
// 2 3 
// 2 3 4 
// 3 
// 3 4 
// 4 

// Subsets
// {}
// 4 
// 3 
// 3 4 
// 2 
// 2 4 
// 2 3 
// 2 3 4 
// 1 
// 1 4 
// 1 3 
// 1 3 4 
// 1 2 
// 1 2 4 
// 1 2 3 
// 1 2 3 4 

// Subarrays
// {}
// 4 
// 3 
// 3 4 
// 2 
// 2 3 
// 2 3 4 
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 

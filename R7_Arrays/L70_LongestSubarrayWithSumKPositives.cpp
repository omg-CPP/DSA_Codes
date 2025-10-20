#include <iostream>
#include <vector>
using namespace std;

int getLongestSubarrayLengthBruteForce(vector<int>& arr, long long k) {
    // Time Complexity : O(n^3)
    int n = arr.size();
    int maxLen = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j++) {
            // add all the elements of subarray arr[i---j]
            long long sum = 0;
            for(int k = i ; k <= j ; k++) {
                sum = sum + arr[k];
            }
            int len = j-i+1;
            if(sum == k) {
                maxLen = max(maxLen,len);
            }
        }
    }
    return maxLen;
}

int getLongestSubarrayLengthBruteForceOptimised(vector<int>& arr, long long k) {
    // Time Complexity : O(n^2)
    int n = arr.size();
    int maxLen = 0;
    for(int i = 0 ; i < n ; i++) {
        long long sum = 0;
        for(int j = i ; j < n ; j++) {
            sum = sum + arr[j];
            if(sum == k) {
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
}

// works for only 0 and positives : Using Two pointers Approach
int getLongestSubarrayLength(vector<int>& arr, long long k) {
    int n = arr.size();
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    while(right < n) {
        // left <= right -> means that subarray exist
        // see Dry Run
        while(left <= right && sum > k) {
            sum = sum - arr[left];
            left++;
        }

        if(left <= right && sum == k) {
            maxLen = max(maxLen,right-left+1);
        }

        right++;
        if(right < n) {
            sum = sum + arr[right];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> a = {2,3,5,1,9};
    long long k = 10;

    int l1 = getLongestSubarrayLengthBruteForce(a,k);
    cout<<"The length of the longest subarray with sum "<<k<<" is : "<<l1<<endl;
    // The length of the longest subarray with sum 10 is : 3

    int l2 = getLongestSubarrayLengthBruteForceOptimised(a,k);
    cout<<"The length of the longest subarray with sum "<<k<<" is : "<<l2<<endl;
    // The length of the longest subarray with sum 10 is : 3

    vector<int> nums = {1,2,3,1,1,1,1,4,2,3};
    long long tar = 6;
    int len = getLongestSubarrayLength(nums,tar);
    cout<<"The length of the longest subarray with sum "<<tar<<" is : "<<len<<endl;
    // The length of the longest subarray with sum 6 is : 4

    int l = getLongestSubarrayLength(a,k);
    cout<<"The length of the longest subarray with sum "<<k<<" is : "<<l<<endl;
    // The length of the longest subarray with sum 10 is : 3
    return 0;
}
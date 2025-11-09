// Leetcode : 1524

#include <iostream>
#include <vector>
using namespace std;

// Brute Force : finding all possible subarrays : TLE
// T.C. = O(n^2)
int numOfSubarraysNaive(vector<int>& arr) {
    int count = 0;
    int n = arr.size();
    for(int i = 0 ; i < n ; i++) {
        int sum = 0;
        for(int j = i ; j < n ; j++) {
            sum += arr[j];
            if(sum % 2 != 0) {
                count++;
            }
        }
    }
    return count;
}

// Using prefix sum : T.C. = O(n) & S.C. = O(n)
int numOfSubarrays(vector<int>& arr) {
    int M = 1e9 + 7;
    int n = arr.size();
    // computing the prefix array
    vector<int> prefixSum(n,0);
    prefixSum[0] = arr[0];
    for(int i = 1 ; i < n ; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    int count = 0;
    int oddCount = 0;
    int evenCount = 1;

    for(int i = 0 ; i < n ; i++) {
        // if prefixSum[i] is even
        if(prefixSum[i] % 2 == 0) { // odd + even = odd
            count = (count + oddCount) % M;
            evenCount++;
        }
        // if prefixSum[i] is odd
        // even + odd = even
        else { // prefixSum[i] % 2 != 0
            count = (count + evenCount) % M;
            oddCount++;
        }
    }
    return count;
}


int main()
{
    vector<int> arr = {2,2,4,5,2,3};
    cout<<numOfSubarraysNaive(arr)<<endl;  // 10
    cout<<numOfSubarrays(arr)<<endl; // 10
    return 0;
}


// 2, 2, 4,  5,  2,  3
// 2, 4, 8, 13, 15, 18

// 2,2,4,5
// 2,4,5
// 4,5
// 5


// 5,2
// 4,5,2
// 2,4,5,2
// 2,2,4,5,2

// 2
// 2,3
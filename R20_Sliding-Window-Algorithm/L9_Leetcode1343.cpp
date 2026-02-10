// Leetcode : 1343

// Number of Subarrays of size K and Average greater than or equal to threshold

// Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.


#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

// T.C. = O(n) + O(n) = O(2n) = O(n)
// S.C. = O(1)

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int n = arr.size();
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += arr[j];
        // doing avg and checking only if the window size is equal to k
        if((j-i+1) == k) {
            if(sum / k >= threshold) {
                count++;
            }
            // window shrink
            sum -= arr[i];
            i++;
        }
        j++;
    }
    return count;
}

int main()
{
    vector<int> arr = {2,2,2,2,5,5,5,8};
    int k = 3;
    int threshold = 4;
    int count = numOfSubarrays(arr,k,threshold);
    cout<<count<<endl; // 3
    // Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
    return 0;
}
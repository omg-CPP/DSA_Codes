// Leetcode : 2551
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// T.C.= O(n) + O(nlogn) + O(k) = O(nlogn)
// S.C. = O(n)
long long putMarbles(vector<int>& weights, int k) {
    int n = weights.size();
    vector<int> pairSum(n-1,0);
    for(int i = 0 ; i < n-1 ; i++) {
        pairSum[i] = weights[i] + weights[i+1];
    }
    sort(begin(pairSum),end(pairSum));

    long maxSum = 0;
    long minSum = 0;

    for(int i = 0 ; i < k-1 ; i++) {
        minSum += pairSum[i];
        maxSum += pairSum[n-2-i];
    }
    return maxSum-minSum;
}

int main()
{
    vector<int> weights = {3,2,1,4,5,2};
    int k = 3;
    cout<<putMarbles(weights,k)<<endl; // 8
    return 0;
}
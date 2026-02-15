// Leetcode : 1423
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(2k)
// S.C. = O(1)

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int lsum = 0;
    int rsum = 0;
    int maxSum = 0;
    for(int i = 0 ; i < k ; i++) {
        lsum += cardPoints[i];
    }
    maxSum = lsum;
    int rIdx = n-1;
    for(int i = k-1 ; i >= 0 ; i--) {
        lsum -= cardPoints[i];
        rsum += cardPoints[rIdx];
        rIdx--;
        maxSum = max(maxSum,lsum+rsum);
    }
    return maxSum;
}

int main()
{
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    int score = maxScore(cardPoints,k);
    cout<<score<<endl; // 12
    return 0;
}
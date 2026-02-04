// Leetcode : 1052
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 1 -> grumpy
// 0 -> not grumpy

// Find the window that has 'most loss of satifaction' or find the window in which most number of customers are left unsatisfied.

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int k = minutes;
    int maxLoss = INT_MIN;
    int prevLoss = 0;
    for(int i = 0 ; i < k ; i++) {
        if(grumpy[i] == 1) {
            prevLoss += customers[i];
        }
    }
    maxLoss = prevLoss; // assume first window is ans
    int maxIdx = 0;
    int i = 1;
    int j = k;
    while(j < n) {
        int currLoss = prevLoss;
        if(grumpy[j] == 1) {
            currLoss += customers[j];
        }
        if(grumpy[i-1] == 1) {
            currLoss -= customers[i-1];
        }
        if(maxLoss < currLoss) {
            maxLoss = currLoss;
            // window start
            maxIdx = i;
        }
        prevLoss = currLoss;
        i++;
        j++;
    }
    // update the grumpy array
    for(int i = maxIdx ; i < maxIdx + k ; i++) {
        grumpy[i] = 0;
    }
    // calculate sum of satifaction
    int satisfaction = 0;
    for(int i = 0 ; i < n ; i++) {
        if(grumpy[i] == 0) {
            satisfaction += customers[i];
        }
    }
    return satisfaction;
}

int main()
{
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3; // k : window size
    int satisfaction = maxSatisfied(customers,grumpy,minutes);
    cout<<satisfaction<<endl; // 16
    return 0;
}
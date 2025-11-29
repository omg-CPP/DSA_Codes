// Leetcode : 1482
// Binary Search on Answers

// m = 2 and k = 3
// arr = {7,7,7,7,13,11,12,7}
// arr = {B,B,B,B, B, B, B,B}
// day 13 -> max ans

// ans will always lie between 7 and 13

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int findMin(vector<int>& bloomDay) {
    int n = bloomDay.size();
    int minElement = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        minElement = min(minElement,bloomDay[i]);
    }
    return minElement;
}

int findMax(vector<int>& bloomDay) {
    int n = bloomDay.size();
    int maxElement = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        maxElement = max(maxElement,bloomDay[i]);
    }
    return maxElement;
}

// O(n)
int possible(vector<int>& bloomDay, int day, int m, int k) {
    int n = bloomDay.size();
    int cnt = 0;
    int noOfBouquets = 0;
    for(int i = 0 ; i < n ; i++) {
        if(bloomDay[i] <= day) {
            cnt++;
        }
        else {
            noOfBouquets += cnt/k;
            cnt = 0;
        }
    }
    noOfBouquets += cnt/k;
    if(noOfBouquets >= m) {
        return true;
    }
    else {
        return false;
    }
}

// T.C. = O((maxi-mini+1)*n)
// S.C. = O(1)
int minDaysBruteForce(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if(m*k > n) {
        return -1;
    }
    int counter = 0;
    for(int i = findMin(bloomDay) ; i <= findMax(bloomDay) ; i++) {
        if(possible(bloomDay,i,m,k) == true) {
            return i;
        }
    }
    return -1;
}

// Binary Search
// T.C. = O(log(maxi-mini+1)*n)
// S.C. = O(1)
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if((long long)m*k > n) {
        return -1;
    }
    int lo = findMin(bloomDay);
    int hi = findMax(bloomDay);
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(possible(bloomDay,mid,m,k) == true) {
            ans = mid;
            hi = mid-1;
        }
        else { // possible(bloomDay,mid,m,k) == false
            lo = mid+1;
        }
    }
    return ans;
    // return lo;
}


int main()
{
    vector<int> bloomDay = {7,7,7,7,13,11,12,7};
    int m = 2; // no of bouquets
    int k = 3; // adjacent flowers
    cout<<minDaysBruteForce(bloomDay,m,k)<<endl; // 12
    cout<<minDays(bloomDay,m,k)<<endl; // 12
    return 0;
}
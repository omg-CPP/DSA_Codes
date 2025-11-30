// GFG :: The Painter's Partition Problem
// Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

// Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

// arr[] = [10 20 30 40] , k = 2 : painters
// Output : 60
// Explanation: A valid optimal partition is - 
// Painter 1 → [10, 20, 30] → time = 60
// Painter 2 → [40] → time = 40
// Job will be complete at time = max(60, 40) = 60

// All possible cases : Each painter atleast gets one job.

// c1 : [10] [20 30 40] :: 10 + 90 :: max = 90
// c2 : [10 20] [30 40] :: 30 + 70 :: max = 70
// c3 : [10 20 30] [40] :: 60 + 40 :: max = 60

// minimum(maximum) -> Binary Search

// c4 : [] [10 20 30 40] X
// c5 : [10 20 30 40] [] X

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int countPainters(vector<int>& arr, int maxBoards) {
    int n = arr.size();
    int painters = 1;
    int boards = 0;
    for(int i = 0 ; i < n ; i++) {
        if(boards + arr[i] <= maxBoards) {
            boards += arr[i];
        }
        else {
            painters++;
            boards = arr[i];
        }
    }
    return painters;
}

int minTime(vector<int>& arr, int k) {
    // code here
    int n = arr.size();
    int lo = *max_element(arr.begin(),arr.end());
    int hi = accumulate(arr.begin(),arr.end(),0);
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(countPainters(arr,mid) > k) {
            lo = mid + 1;
        }
        else { // countPainters(arr,mid) <= k
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    return 0;
}
// Leetcode : 875
// Binary Search On Answers
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

double calculateTime(vector<int>& piles, int k) {
    int n = piles.size();
    double totalHours = 0; 
    for(int i = 0 ; i < n ; i++) {
        totalHours += ceil((double)piles[i]/(double)k);
    }
    return totalHours;
}

int maximumInArray(vector<int>& piles) {
    int n = piles.size();
    int maxElement = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        maxElement = max(maxElement,piles[i]);
    }
    return maxElement;
}

// T.C. = O(N*Max(Piles))
// S.C. = O(1)
int minEatingSpeedBruteForce(vector<int>& piles, int h) {
    int n = piles.size();
    int maxElement = maximumInArray(piles);
    for(int i = 1 ; i <= maxElement ; i++) {
        if(calculateTime(piles,i) <= h) {
            return i;
        }
    }
    return -1;
}

// T.C. = O(N*log(Max(Piles)))
// S.C. = O(1)
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int lo = 1;
    int hi = maximumInArray(piles);
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(calculateTime(piles,mid) <= h) {
            ans = mid;
            hi = mid-1;
        }
        else { // calculateTime(piles,mid) > h
            lo = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<minEatingSpeedBruteForce(piles,h)<<endl; // 4
    cout<<minEatingSpeed(piles,h)<<endl; // 4
    return 0;
}

// limit :: [1,11]

// [3,6,7,11], h = 8
// k = 1 banana/hr
// total time = 3 + 6 + 7 + 11 = 27 > 8

// k = 2 banana/hr
// total time = 2 + 3 + 4 + 6 = 15 > 8

// k = 3 banana/hr
// total time = 1 + 2 + 3 + 4 = 10 > 8

// k = 4 banana/hr
// total time = 1 + 2 + 2 + 3 = 8 == 8

// k = 5 banana/hr
// total time = 1 + 2 + 2 + 3 = 8

// k = 6 banana/hr
// total time = 1 + 1 + 2 + 2 = 6

// limit = maxElementOfTheArray = 11
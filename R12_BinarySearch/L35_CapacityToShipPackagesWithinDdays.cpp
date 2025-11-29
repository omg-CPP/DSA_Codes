// Leetcode : 1011
// Binary Search On Answers

// weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Range : [minElement(arr),sumOfAllElements(arr)]
// Range : [10,55]
// And below cap = 10, it will result in no answer.
// Suppose cap = 9, so package 10 will never be shipped, so ans = -1;
// At and After Cap = 55 it could be done in 1 day.


#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int findMax(vector<int>& weights) {
    int n = weights.size();
    int maxElement = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        maxElement = max(maxElement,weights[i]);
    }
    return maxElement;
}

int maxLimit(vector<int>& weights) {
    int n = weights.size();
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += weights[i];
    }
    return sum;
}

// for cap = 10
// day 1 :: [1,2,3,4]
// day 2 :: [5]
// day 3 :: [6]
// day 4 :: [7]
// day 5 :: [8]
// day 6 :: [9]
// day 7 :: [10]

int possibleToShip(vector<int>& weights, int cap, int days) {
    int n = weights.size();
    int daysToShip = 1;
    int load = 0;
    for(int i = 0 ; i < n ; i++) {
        if(load + weights[i] > cap) {
            daysToShip += 1;
            load = weights[i];
        }
        else {
            load += weights[i];
        }
    }
    if(daysToShip <= days) {
        return true;
    }
    else {
        return false;
    }
}

// T.C. = O((sum-max+1)*n)
// S.C. = O(1)
int shipWithinDaysBruteForce(vector<int>& weights, int days) {
    int n = weights.size();
    for(int i = findMax(weights) ; i <= maxLimit(weights) ; i++) {
        if(possibleToShip(weights,i,days) == true) {
            return i;
        }
    }
    return -1;
}

// T.C. = O(log(sum-max+1)*n)
// S.C. = O(1)
int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int lo = findMax(weights);
    int hi = maxLimit(weights);
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(possibleToShip(weights,mid,days) == true) {
            ans = mid;
            hi = mid-1;
        }
        else { // possibleToShip(weights,mid,days) == false
            lo = mid+1;
        }
    }
    return ans;
}


int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout<<shipWithinDaysBruteForce(weights,days)<<endl; // 15
    cout<<shipWithinDays(weights,days)<<endl; // 15
    return 0;
}

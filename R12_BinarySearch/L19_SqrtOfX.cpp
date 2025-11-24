// Leetcode : 69
// return floor of ans
// find the max integer which on squaring <= x
// range : 1 to x
// min / max

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Brute Force : Using built-in functions
float mySqrtNaive(int x) {
    return sqrt(x);
}

// Linear Search : O(n)
// 28 : 5
int mySqrtBetter(int x) {
    int ans = 1;
    for(int i = 1 ; i <= x ; i++) {
        if(i*i <= x) {
            ans = i;
        }
        else { // i*i > x
            break;
        }
    }
    return ans;
}

int mySqrt(int x) {
    if(x == 0 || x == 1) {
        return x;
    }
    int lo = 1;
    int hi = x;
    int ans = 1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if((long long)mid*mid == x) {
            return mid;
        }
        else if((long long)mid*mid < x) {
            ans = mid;
            lo = mid + 1;
        }
        else { // mid*mid > x
            hi = mid - 1;
        }
    }
    return ans;
}

int mySqrtOptimal(int x) {
    if(x == 0 || x == 1) {
        return x;
    }
    int lo = 1;
    int hi = x;
    int ans = 1;
    while(lo <= hi) {
        long long mid = lo + (hi-lo) / 2;
        long long val = mid * mid;
        if(val <= x) {
            ans = mid;
            lo = mid + 1;
        }
        else { // val > x
            hi = mid - 1;
        }
    }
    return ans;
}

// 1, -----------, 36
// mid = 18
// lo = 1 && hi = 17
// mid = 9
// lo = 1 && hi = 8
// mid = 4
// ans = 4 && lo = 5 && hi = 8
// mid = 6
// ans = 6 && lo = 7 && hi = 8
// mid = 7
// lo = 7 && hi = 6
// lo > hi :: loop terminates
// ans = 6

int main()
{
    int x = 28;
    cout<<mySqrtNaive(x)<<endl; // 5.2915
    cout<<mySqrtBetter(x)<<endl; // 5
    cout<<mySqrt(x)<<endl; // 5
    cout<<mySqrt(x)<<endl; // 5
    return 0;
}

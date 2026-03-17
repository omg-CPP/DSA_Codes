// Leetcode : 2134

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cmath>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;

// Approach I
// T.C. = O(2N) = O(N)
//        temp[]
// S.C. = O(2N)
int minSwaps(vector<int>& nums) {
    // sliding window with window size = k
    int n = nums.size();
    vector<int> temp(2*n,0);
    for(int i = 0 ; i < 2*n ; i++) {
        temp[i] = nums[i%n];
    }
    int i = 0;
    int j = 0;
    int totalOnes = 0;
    for(int& num : nums) {
        totalOnes += (num == 1);
    }
    // edge cases
    if(totalOnes <= 1) {
        return 0;
    }
    int currOnes = 0;
    int minSwaps = INT_MAX;
    while(j < temp.size() && i < nums.size()) {
        currOnes += (temp[j] == 1);
        // shrink phase
        if(j-i+1 > totalOnes) {
            currOnes -= (temp[i] == 1);
            i++;
        }
        // window size = k
        if(j-i+1 == totalOnes) {
            int swaps = totalOnes - currOnes;
            minSwaps = min(minSwaps,swaps);
        }
        j++;
    }
    return minSwaps;
}


// Approach II
// T.C. = O(2N) = O(N)
// S.C. = O(1)
int minSwaps_Optimal(vector<int>& nums) {
    // sliding window with window size = k
    int n = nums.size();
    int i = 0;
    int j = 0;
    int totalOnes = 0;
    for(int& num : nums) {
        totalOnes += (num == 1);
    }
    // edge cases
    if(totalOnes <= 1) {
        return 0;
    }
    int currOnes = 0;
    int minSwaps = INT_MAX;
    // to avoid duplicate windows
    while(j < 2*n && i < n) {
        currOnes += (nums[j%n] == 1);
        // shrink phase
        if(j-i+1 > totalOnes) {
            currOnes -= (nums[i%n] == 1);
            i++;
        }
        // window size = k
        if(j-i+1 == totalOnes) {
            int swaps = totalOnes - currOnes;
            minSwaps = min(minSwaps,swaps);
        }
        j++;
    }
    return minSwaps;
}


int main()
{
    return 0;
}
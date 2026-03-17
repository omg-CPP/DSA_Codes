// Leetcode : 1151 and GFG : Min Swaps to Group 1's

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

int minSwaps(vector<int>& nums) {
    // sliding window with window size = k
    int n = nums.size();
    int i = 0;
    int j = 0;
    int totalOnes = 0;
    for(int& num : nums) {
        totalOnes += (num == 1);
    }
    // edge cases
    if(totalOnes == 0) {
        return -1;
    }
    if(totalOnes == 1) {
        return 0;
    }
    int currOnes = 0;
    int minSwaps = INT_MAX;
    while(j < n) {
        currOnes += (nums[j] == 1);
        // shrink phase
        if(j-i+1 > totalOnes) {
            currOnes -= (nums[i] == 1);
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
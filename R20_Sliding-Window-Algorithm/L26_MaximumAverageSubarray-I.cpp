// Leetcode : 643

#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double maxAvg = -1e9;
    int sum = 0;
    // sliding window
    int i = 0;
    int j = 0;
    while(j < n) {
        sum += nums[j];

        // shrink phase
        if(j-i+1 > k) {
            sum -= nums[i];
            i++;
        }

        // when the window == k
        if(j-i+1 == k) {
            maxAvg = max(maxAvg, (double)sum/k);
        }
        j++;
    }
    return maxAvg;
}

int main()
{
    return 0;
}
// Leetcode : 2078

// There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

// Return the maximum distance between two houses with different colors.

// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(N^2)
// S.C. = O(1)
int maxDistanceNaive(vector<int>& colors) {
    int n = colors.size();
    int maxDist = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(colors[i] != colors[j]) {
                maxDist = max(maxDist,abs(i-j));
            }
        }
    }
    return maxDist;
}

// 🎯 The Core Insight
// The maximum distance between two different colored houses MUST involve either:
// The first house (index 0) OR
// The last house (index n-1)

// 🤔 Why is this true?
// Think of it this way: If you want the maximum distance between two different colored houses, you need to stretch as far as possible across the street.
// There are only two "anchor points" that can give you the maximum stretch:
// Start from the left end (index 0) and find the farthest different color to the right
// Start from the right end (index n-1) and find the farthest different color to the left

// T.C. = O(N)
// S.C. = O(1)
int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int maxDist = 0;
    int left = 0;
    int right = n-1;
    // calculating max distance from left end
    while(right > 0 && colors[0] == colors[right]) {
        right--;
    }
    int maxLeftDist = right;
    // calculating max distance from right end
    while(left < n && colors[left] == colors[n-1]) {
        left++;
    }
    int maxRightDist = n-1-left;
    return max(maxLeftDist,maxRightDist);
}

int main()
{
    vector<int> colors = {1,8,3,8,3};
    cout<<maxDistanceNaive(colors)<<endl; // 4
    cout<<maxDistance(colors)<<endl; // 4
    return 0;
}

// R G G B G B R R R


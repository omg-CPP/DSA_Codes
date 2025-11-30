// Leetcode : 1539
// Binary Search On Answers

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.



#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(1)
int findKthPositiveBruteForce(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] <= k) {
            k++;
        }
        else {
            break;
        }
    }
    return k;
}

// T.C. = O(n)
// S.C. = O(1)
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    
}


int main()
{
    return 0;
}
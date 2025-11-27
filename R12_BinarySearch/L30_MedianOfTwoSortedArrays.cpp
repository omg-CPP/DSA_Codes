// Leetcode : 4

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force : Merging two sorted arrays
// T.C. = O(n1+n2)
// S.C. = O(n1+n2)
double findMedianSortedArrays_Naive(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> mergeArray(n1+n2,0);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n1 && j < n2) {
        if(nums1[i] <= nums2[j]) {
            mergeArray[k] = nums1[i];
            i++;
            k++;
        }
        else { // nums1[i] > nums2[j]
            mergeArray[k] = nums2[j];
            j++;
            k++;
        }
    }
    // if some elements of nums2 are left
    if(i == n1) {
        while(j < n2) {
            mergeArray[k] = nums2[j];
            j++;
            k++;
        }
    }
    // if some elements of nums1 are left
    if(j == n2) {
        while(i < n1) {
            mergeArray[k] = nums1[i];
            i++;
            k++;
        }
    }
    // odd
    if((n1+n2) % 2 != 0) {
        return (double)mergeArray[(n1+n2)/2];
    }
    // even
    return (double)((double)mergeArray[(n1+n2)/2] + (double)mergeArray[((n1+n2)/2)-1])/2.0;
}

// Better Approach : Without using Extra Space
// T.C. = O(n1+n2)
// S.C. = O(1)
double findMedianSortedArrays_Better(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int i = 0;
    int j = 0;
    int idx2 = n/2;
    int idx1 = idx2 - 1;
    int cnt = 0;
    int idx1Ele = -1;
    int idx2Ele = -1;
    
    while(i < n1 && j < n2) {
        if(nums1[i] <= nums2[j]) {
            if(cnt == idx1) idx1Ele = nums1[i];
            if(cnt == idx2) idx2Ele = nums1[i];
            cnt++;
            i++;
        }
        else { // nums1[i] > nums2[j]
            if(cnt == idx1) idx1Ele = nums2[j];
            if(cnt == idx2) idx2Ele = nums2[j];
            cnt++;
            j++;
        }
        if(idx1Ele != -1 && idx2Ele != -1) {
            break;
        }
    }

    if(i == n1) {
        while(j < n2) {
            if(cnt == idx1) idx1Ele = nums2[j];
            if(cnt == idx2) idx2Ele = nums2[j];
            cnt++;
            j++;
        }
    }

    if(j == n2) {
        while(i < n1) {
            if(cnt == idx1) idx1Ele = nums1[i];
            if(cnt == idx2) idx2Ele = nums1[i];
            cnt++;
            i++;
        }
    }
    if(n % 2 != 0) {
        return (double)idx2Ele;
    }
    return (double)((double)(idx1Ele + idx2Ele)) / 2.0;
}

// Optimised Solution : Binary Search
// On the basis of symmetry 
// T.C. = O(min(log(n1),log(n2)))
// S.C. = O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1 > n2) {
        return findMedianSortedArrays(nums2,nums1);
    }
    // we are solving for nums1 is a smaller array
    int lo = 0;
    int hi = n1;
    // how many elements should be there on the left
    // if n = 10 :: left = 11/2 = 5
    // if n = 5  :: left = 6/2 = 3
    int left = (n1+n2+1)/2;
    int n = n1+n2;
    while(lo <= hi) {
        int mid1 = lo + (hi-lo) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MAX;
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1-1 >= 0) l1 = nums1[mid1-1];
        if(mid2-1 >= 0) l2 = nums2[mid2-1];

        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 != 0) {
                return (double)max(l1,l2);
            }
            else { // even no of elements
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        else if(l1 > r2) {
            hi = mid1 - 1;
        }
        else { // l2 > r1
            lo = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}


// eg. = {1,2,3,3,4 | 6,7,10,12,15}
// median =( 4 + 6) / 2 = 5

// arr1 = [1,3,4,7,10,12]
// arr2 = [2,3,6,15]

// focus is on that how many elements from arr1 and how many elements from arr2 should be on left side to form a valid symmetry

// [1,3,4] | [7,10,12]  :: sorted line
// [2,3]   | [6,15]     :: sorted line
 
// for valid symmetry
// 4 < 6    &&     3 < 7
// median = (max(3,4) + min(6,7)) / 2


// arr1 = [7,12,14,15]
// arr2 = [1,2,3,4,9,11]

// apply binary search to identify that how many elements will be on the left half on the shorter array to get a better time complexity

// apply binary search on arr1
// arr1 = [7,12,14,15]

// 0 -> not picking any element
// 4 -> picking all

// mid = 2 : picking 2 elements from arr1

// [7,12]   l1  | r1   [14,15]
// [1,2,3]  l2  | r2   [4,9,11]

// 12 < 4  =>  X   =>   l1 > r2  =>  hi = mid - 1
// 3 < 14  =>  Correct

// 0 -> lo 
// 1 -> hi
// mid = 0

// []          l1   |  r1 [7,12,14,15]
// [1,2,3,4,9] l2   |  r2  [11]

// INT_MIN < 11
// 9 < 7  =>  X   =>   l2 > r1 => lo = mid + 1

// lo = 1
// hi = 1
// mid1 = 1 :: picking 1 element from arr1

// [7]          l1   |  r1 [12,14,15]
// [1,2,3,4]    l2   |  r2  [9,11]

// 7 < 9  =>  Correct
// 4 < 12  =>  Correct
// Valid Configuration

// mid2 = 4

// l1 = arr1[mid1-1]
// r1 = arr1[mid1]

// l2 = arr2[mid2-1]
// r2 = arr2[mid2]

// median = (max(3,4) + min(6,7)) / 2


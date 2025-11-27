// Leetcode : 1095

#include <iostream>
#include <vector>
using namespace std;

// Brute Force : O(n)

// int findInMountainArray(int target, MountainArray& mountainArr) {
//     // mountainArr is a object of class MountainArray
//     int n = mountainArr.length();
//     for(int i = 0 ; i < n ; i++) {
//         if(mountainArr.get(i) == target) {
//             return i;
//         }
//     }
//     return -1;
// }


// *******************************************************************************

// O(logn)
// for finding peak index
// int peakIndexInMountainArray(MountainArray& mountainArr) {
//     // single peak
//     // Binary Search
//     int n = mountainArr.length();
//     int lo = 1;
//     int hi = n-2;
//     while(lo <= hi) {
//         int mid = lo + (hi - lo) / 2;
//         int midVal = mountainArr.get(mid);
//         int leftVal = mountainArr.get(mid-1);
//         int rightVal = mountainArr.get(mid+1);
//         if(midVal > leftVal && midVal > rightVal) {
//             return mid;
//         }
//         // if mid is in increasing part
//         else if(midVal > leftVal) {
//             lo = mid + 1;
//         }
//         // if mid is in decreasing part
//         else { // midVal > rightVal
//             hi = mid - 1;
//         }
//     }
//     return -1;
// }

// O(logn)
// // Ascending Part
// int binarySearchOnLeftPart(int target, MountainArray& mountainArr, int lo, int hi) {
//     while(lo <= hi) {
//         int mid = lo + (hi-lo) / 2;
//         int midVal = mountainArr.get(mid);
//         if(midVal == target) {
//             return mid;
//         }
//         else if(midVal < target) {
//             lo = mid + 1;
//         }
//         else { // midVal > target
//             hi = mid - 1;
//         }
//     }
//     return -1;
// }

// O(logn)
// // Descending Part
// int binarySearchOnRightPart(int target, MountainArray& mountainArr, int lo, int hi) {
//     while(lo <= hi) {
//         int mid = lo + (hi-lo) / 2;
//         int midVal = mountainArr.get(mid);
//         if(midVal == target) {
//             return mid;
//         }
//         else if(midVal < target) {
//             hi = mid - 1;
//         }
//         else { // midVal > target
//             lo = mid + 1;
//         }
//     }
//     return -1;
// }

// // T.C. = O(Log(N))
// // S.C. = O(1)
// int findInMountainArray(int target, MountainArray& mountainArr) {
//     // mountainArr is a object of class MountainArray
//     int n = mountainArr.length();
//     int peakIdx = peakIndexInMountainArray(mountainArr);
//     // applying binary search to first sorted half
//     int res = binarySearchOnLeftPart(target,mountainArr,0,peakIdx);
//     if(res != -1) {
//         return res;
//     }
//     res = binarySearchOnRightPart(target,mountainArr,peakIdx+1,n-1);
//     return res;
// }


int main()
{
    return 0;
}
// GFG : Aggressive Cows

// ou are given an array with unique elements of stalls[], which denote the positions of stalls.

// k which denotes the number of aggressive cows.

// The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// mimimum disatnce will always be there on sorted stalls

// eg : stalls = [0,3,4,7,10,9] && cows = 4
// sort :: [0  3   4   7  9  10]
//         c1  c2  c3  c4   
// min dist = min(3,1,3) = 1

//         [0  3   4   7   9   10]
//         c1      c2      c3  c4
// min dist = min(4,5,1) = 1

//         [0  3   4   7   9   10]
//         c1      c2  c3      c4
// min dist = min(4,3,3) = 3

// we need to maximise the minimum distance which will be 3 in this case

// minLimit will be 1 as all stalls are unique

// cows >= 2
// Range : [1,(max-min)]
//         [0  3   4   7   9   10]
//         c1                  c2


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

// int findMin(vector<int>& stalls) {
//     int n = stalls.size();
//     int minElement = INT_MAX;
//     for(int i = 0 ; i < n ; i++) {
//         minElement = min(minElement,stalls[i]);
//     }
//     return minElement;
// }

// int findMax(vector<int>& stalls) {
//     int n = stalls.size();
//     int maxElement = INT_MIN;
//     for(int i = 0 ; i < n ; i++) {
//         maxElement = max(maxElement,stalls[i]);
//     }
//     return maxElement;
// }

// O(n)
bool canWePlaceCows(vector<int>& stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for(int i = 1 ; i < n ; i++) {
        if(stalls[i]-last >= dist) {
            cntCows++;
            last = stalls[i];
        }
    }
    // able to place all cows maintaining the minimum distance alloted by the function above
    if(cntCows >= cows) {
        return true;
    }
    else {
        return false;
    }
}

// T.C. = O((max-min+1)*n)
// S.C. = O(1)
int aggressiveCowsBruteForce(vector<int>& stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int ans = 0;
    // int maxLimit = findMax(stalls) - findMin(stalls);
    int maxLimit = stalls[n-1] - stalls[0]; // sorted array
    for(int i = 1 ; i <= maxLimit ; i++) {
        if(canWePlaceCows(stalls,i,k) == true) {
            // eg = {1,5,17} && cows = 2
            // In this case ans comes at last case
            if(i == maxLimit) {
                return i;
            }
            continue;
        }
        else {
            return i-1;
        }
    }
    return -1; // general statement
}

// Binary Search On Answers
// T.C. = O(log(max-min+1)*n)
// S.C. = O(1)
int aggressiveCows(vector<int>& stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(),stalls.end()); // nlogn
    int ans = 0;
    int lo = 1;
    // int hi = findMax(stalls) - findMin(stalls);
    int hi = stalls[n-1] - stalls[0]; // sorted array
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(canWePlaceCows(stalls,mid,k) == true) {
            ans = mid;
            lo = mid+1;
        }
        else { // canWePlaceCows(stalls,mid,k) == false
            hi = mid-1;
        }
    }
    return ans;  
    // return hi; 
}


int main()
{
    vector<int> stalls = {0,3,4,7,10,9};
    int k = 4;
    cout<<aggressiveCowsBruteForce(stalls,k)<<endl; // 3
    cout<<aggressiveCows(stalls,k)<<endl; // 3
    return 0;
}

// eg = {0,3,4,7,10,9}

//              {0,  3,  4,  7,  9,  10}
// dist = 1 ::   c1  c2  c3  c4
// dist = 2 ::   c1  c2      c3  c4
// dist = 3 ::   c1  c2      c3      c4
// dist = 4 ::   c1      c2      c3        X

// eg = {1,5,17} && cows = 2
// i = 1 to 16
// i = 16
// {1  5  17}
// c1     c2


// stalls = 6 4 3 16 20 7 18 10
// k = 5
// Output : 3

// M1 : With sorting
// stalls = [3  4  6  7  10  16  18  20]
// dist : 1 to (20-3) = 1 to 17
// stalls = [3   4   6   7   10   16   18   20]
// dist 1 : c1  c2   c3  c4  c5
// dist 2 : c1       c2      c3   c4   c5
// dist 3 : c1       c2      c3   c4         c5
// dist 4 : c1           c2       c3         c4   X
// Therefore 3 is ans

// M2 : Without Sorting
// stalls = [6   4   3   16   20   7   18   10]
// dist 1 : c1           c2   c3       c4        X
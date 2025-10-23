// Leetcode : 3495

// You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.

// In one operation, you can:

// Select two integers a and b from the array.
// Replace them with floor(a / 4) and floor(b / 4).
// Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // T.C. = N*log4(r)
    // L = 1, 1*4, 4*4, 16*4, 64*4-----, r
    // L = 4^0, 4^1, 4^2, 4^3, 4^4, ----, 4^t

    // r = 4^t => log4(r) = t => [t = log4(r)]

    // O(t+1) = O(t) = O(log4(r))

    // S.C. = O(1)
    long long solve(long long l, long long r) {
        long long L = 1; // R = 4*L - 1
        long long S = 1;
        long long steps = 0;
        while(L <= r) {
            long long R = 4*L - 1;
            long long start = max(L,l);
            long long end = min(R,r);
            if(start <= end) {
                steps += (end-start+1)*S;
            }
            S += 1;
            L *= 4;
        }
        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long result = 0;
        for(int i = 0 ; i < n ; i++) {
            long long l = queries[i][0];
            long long r = queries[i][1];
            long long steps = solve(l,r);
            result += (steps+1)/2;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> queries = {{1,2},{2,4}};
    cout<<s.minOperations(queries)<<endl;        // 3
    return 0;
}


// [L,R]
// [1,3] :: ops to make 0 array : 1 step
// [4,15] :: ops to make 0 array : 2 steps
// [16,63] :: ops to make 0 array : 3 steps
// [64,255] :: ops to make 0 array : 4 steps


// [[1,2],[2,4]]

// 1st query : [1,2] : 1 step : 2*1 = 2 => step = 2/2 = 1
// 2nd query : [2,4] : 4 steps total => 4/2 = 2
//                        [2,3] : 2*1 = 2
//                        [4] : 1*2 = 2
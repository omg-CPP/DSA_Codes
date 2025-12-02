// Leetcode : 3623

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// T.C. = O(N)
// S.C. = O(K) 
int countTrapezoids(vector<vector<int>>& points) {
    int M = 1e9 + 7;
    unordered_map<int,int> mp; // {y,count}
    for(auto& point : points) {
        int y = point[1];
        mp[y]++;
    }

    long long result = 0; // count of all trapezoids
    long long prevHorizontalLines = 0;

    for(auto& it : mp) {
        int count = it.second;
        long long horizontalLines = (long long)count * (count-1) / 2;
        result += horizontalLines * prevHorizontalLines;
        prevHorizontalLines += horizontalLines;
    }
    return result % M;
}

int main()
{
    return 0;
}
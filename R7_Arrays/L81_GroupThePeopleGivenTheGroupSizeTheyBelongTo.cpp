// Leetcode : 1282
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(n)
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    // groupSizes = [3,3,3,3,3,1,3]
    int n = groupSizes.size();
    vector<vector<int>> result;
    // 1 <= groupSizes[i] <= n
    // [7,7,7,7,7,7,7]
    // [[0,1,2,3,4,5,6]]
    vector<vector<int>> mp(n+1,vector<int>(0)); // key - size && val - people {}
    for(int i = 0 ; i < n ; i++) {
        int L = groupSizes[i];
        mp[L].push_back(i);
        if(mp[L].size() == L) {
            result.push_back(mp[L]);
            mp[L] = {};
        }
    }
    return result;
}

int main()
{
    vector<int> groupSizes = {3,3,3,3,3,1,3};
    vector<vector<int>> result = groupThePeople(groupSizes);
    for(int i = 0 ; i < result.size() ; i++) {
        for(int j = 0 ; j < result[i].size() ; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 0 1 2 
// 5
// 3 4 6
// Leetcode : 735

// T.C. = O(n+n) = O(2n) = O(n)
// S.C. = o(n)

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> list;
    for(int i = 0 ; i < n ; i++) {
        if(asteroids[i] > 0) {
            list.push_back(asteroids[i]);
        }
        else { // asteroids[i] < 0
            while(list.size() > 0 && list.back() > 0 && list.back() < abs(asteroids[i])) {
                list.pop_back();
            }
            if(list.size() > 0 && list.back() > 0 && list.back() == abs(asteroids[i])) {
                list.pop_back();
            }
            else {
                if(list.size() == 0 || list.back() < 0) {
                    list.push_back(asteroids[i]);
                }
            }
        }
    }
    return list;
}

int main()
{
    vector<int> asteroids = {4,7,1,1,2,-3,-7,17,15,-16};
    vector<int> ans = asteroidCollision(asteroids);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 4 17 
    cout<<endl;

    vector<int> asteroid = {4,7,1,1,2,-3,-7,17,15,-18,-19};
    vector<int> res = asteroidCollision(asteroid);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    // -18 -19 
    cout<<endl;
    return 0;
}
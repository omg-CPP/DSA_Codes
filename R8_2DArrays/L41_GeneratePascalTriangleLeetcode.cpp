#include <iostream>
#include <vector>

// leetcode 118
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    // for(int i = 1 ; i <= numRows ; i++) {
    //     vector<int> v(i);
    //     ans.push_back(v);
    // }
    // ans = {{0},{0,0},{0,0,0},{0,0,0,0},{0,0,0,0,0}}

    // generate
    for(int i = 0 ; i < numRows ; i++) {
        vector<int> v(i+1);
        ans.push_back(v);
        for(int j = 0 ; j <= i ; j++) {
            if(j == 0 || i == j) {
                ans[i][j] = 1;
            }
            else {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter rows : ";
    cin>>n;
    vector<vector<int>> result = generate(n);
    // print the 2D Vector
    for(int i = 0 ; i < result.size() ; i++) {
        for(int j = 0 ; j < result[i].size() ; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter rows : 5
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 

// Enter rows : 6
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
// 1 5 10 10 5 1 

// Enter rows : 10
// 1 
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// 1 6 15 20 15 6 1
// 1 7 21 35 35 21 7 1
// 1 8 28 56 70 56 28 8 1
// 1 9 36 84 126 126 84 36 9 1
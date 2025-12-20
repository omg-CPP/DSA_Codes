#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// subsets : {1,2,3}
// {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}}

void printSubset(int arr[], int n, int idx, vector<int> ans, int k) {
    if(idx == n) {
        if(ans.size() == k) {
            for(int i = 0 ; i < ans.size() ; i++) {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // No need to check as not subsequence of size k 
    // wiil be obtained
    if(ans.size() + (n-idx) < k) {
        return;
    }
    // do not add
    printSubset(arr,n,idx+1,ans,k);
    // add
    ans.push_back(arr[idx]);
    printSubset(arr,n,idx+1,ans,k);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    int k = 3;
    printSubset(arr,n,0,v,k);
    // Subsequencse of length k = 3
    // 3 4 5 
    // 2 4 5 
    // 2 3 5 
    // 2 3 4 
    // 1 4 5 
    // 1 3 5 
    // 1 3 4 
    // 1 2 5 
    // 1 2 4 
    // 1 2 3 
    return 0;
}
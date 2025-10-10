#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Brute force : O(N^2)
    // int n = 6;
    // int arr[n] = {10,22,12,3,0,6};

    // for(int i = 0 ; i < n ; i++) {
    //     bool leader = true;
    //     for(int j = i+1 ; j < n ; j++) {
    //         if (arr[j] > arr[i]) {
    //             leader = false;
    //             break;
    //         }
    //     }    
    //     if(leader == true) {
    //         cout<<arr[i]<<" is a leader"<<endl;
    //     }
    // }


    // Optimal force : O(N)
    int n = 6;
    int arr[n] = {10,22,12,3,0,6};

    vector<int> ans;
    int max = arr[n-1];
    ans.push_back(arr[n-1]);

    for(int i = n-2 ; i >= 0 ; i--) {
        if(arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }    
    }
    // printing reverse vector
    for(int i = ans.size()-1 ; i >= 0 ; i--) {
        cout<<ans[i]<<" ";
    }
    // 22 12 6 
    return 0;
}

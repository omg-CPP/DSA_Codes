#include <iostream>
#include <vector>
#include <algorithm>
// Leetcode Question
using namespace std;
int main()
{
    // Two Pointers
    vector<int> v;
    cout<<v.size()<<endl; // 0
    int n;
    cout<<"Enter array size : ";
    cin>>n;

    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    int target;
    cout<<"Enter target : ";
    cin>>target;

    int lo = 0;
    int hi = n-1;
    sort(v.begin(),v.end());
    while(lo < hi) {
        int sum = v[lo] + v[hi];
        if(sum == target) {
            cout<<v[lo]<<","<<v[hi]<<endl;
        }
        else if(sum < target) {
            lo++;
        }
        else { // sum > target
            hi--;
        }
    }
    return 0;
}
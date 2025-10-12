#include <iostream>
#include <vector>
using namespace std;
int main()
{
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

    cout<<v.size()<<endl; // 8
    cout<<v.capacity()<<endl; // 8

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 1 3 2 4 3 4 1 6 
    cout<<endl;

    int target;
    cout<<"Enter target : ";
    cin>>target;

    // Brute force : O(N^2)
    // No repetition will occur
    for(int i = 0 ; i < v.size()-1 ; i++) {
        for(int j = i+1 ; j < v.size() ; j++) {
            if(v[i] + v[j] == target) {
                cout<<"index : "<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }
    return 0;
}

// 0
// Enter array size : 8
// Enter elements : 1 3 2 4 3 4 1 6
// 8
// 8
// 1 3 2 4 3 4 1 6 
// Enter target : 7
// index : (0,7)
// index : (1,3)
// index : (1,5)
// index : (3,4)
// index : (4,5)
// index : (6,7)
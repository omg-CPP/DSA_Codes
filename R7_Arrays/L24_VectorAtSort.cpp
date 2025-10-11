#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);

    cout<<v[2]<<endl; // 6
    cout<<v.at(2)<<endl; // 6

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 9 10 6 1 

    cout<<endl;

    sort(v.begin(),v.end());

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 1 6 9 10 

    cout<<endl;
    return 0;
}
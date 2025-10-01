
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [] -> capture clause
// auto -> return type of the lambda function


int main()
{
    vector<int> v = {3,2,1,6};
    sort(v.begin(), v.end());
    // 1 2 3 6
    cout<<endl;

    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    for(auto& i : v) {
        cout<<i<<" ";
    }
    // 6 3 2 1 
    cout<<endl;

    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });
    for(auto& i : v) {
        cout<<i<<" ";
    }
    // 1 2 3 6
    cout<<endl;

    vector<int> v2 = {5,3,7,2,1,6,4};

    // *************************************************************

    auto lambda = [](int a, int b) {
        return a > b;
    };

    sort(v2.begin(), v2.end(), lambda);

    for(auto& i : v2) {
        cout<<i<<" ";
    }
    // 7 6 5 4 3 2 1
    cout<<endl;
    return 0;
}
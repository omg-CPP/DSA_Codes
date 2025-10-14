#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVector(vector<int>& v) {
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void sortArrayOf01(vector<int>& v) {
    int n = v.size();
    int nofzeros = 0;
    int nofones = 0;
    for(int i = 0 ; i < n ; i++) {
        if(v[i] == 0) {
            nofzeros++;
        }
        else {
            nofones++;
        }
    }

    // filling elements

    for(int i = 0 ; i < n ; i++) {
        if(i < nofzeros) {
            v[i] = 0;
        }
        else {
            v[i] = 1;
        }
    }
}

int main()
{
    // M1 - Two Pass Method
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);

    displayVector(v); // 0 1 0 0 1 1 0 1

    // inbuilt function to sort a vector
    // sort(v.begin(),v.end());
    // displayVector(v); // 0 0 0 0 1 1 1 1

    sortArrayOf01(v);

    displayVector(v); // 0 0 0 0 1 1 1 1 

    return 0;
}
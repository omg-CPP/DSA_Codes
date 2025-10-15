#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& v) {
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void sortArrayOf012(vector<int>& v) {
    int n = v.size();
    int nofzeros = 0;
    int nofones = 0;
    int noOftwos = 0;
    for(int i = 0 ; i < n ; i++) {
        if(v[i] == 0) {
            nofzeros++;
        }
        else if(v[i] == 1) {
            nofones++;
        }
        else {
            noOftwos++;
        }
    }

    // filling elements

    for(int i = 0 ; i < n ; i++) {
        if(i < nofzeros) {
            v[i] = 0;
        }
        else if(i < (nofzeros+nofones)){
            v[i] = 1;
        }
        else {
            v[i] = 2;
        }
    }
}

int main()
{

    // leetcode 75
    // Sort Colors
    // M1 : Two Pass Solution

    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);

    displayVector(v); // 2 1 0 1 2 0 1 0 2 1 0

    sortArrayOf012(v);

    displayVector(v); // 0 0 0 0 1 1 1 1 2 2 2 
    return 0;
}
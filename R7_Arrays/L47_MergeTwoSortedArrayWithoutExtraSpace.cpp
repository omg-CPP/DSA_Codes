#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& v) {
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> mergeTwoSortedArrays(vector<int>& v1, vector<int>& v2) {

    int m = v1.size();
    int n = v2.size();
    int i = m-1; // v1
    int j = n-1; // v2
    int k = m+n-1;

    while(i >= 0 && j >= 0) {
        if(v1[i] >= v2[j]) {
            v1[k] = v1[i];
            i--;
            k--;
        }
        else { // v1[i] < v2[j]
            v1[k] = v2[j];
            j--;
            k--;
        }
    }

    if(i == -1) { // v1 is covered
        while(j >= 0) {
            v1[k] = v2[j];
            j--;
            k--;
        }
    }

    if(j == -1) { // v2 is covered
        while(i >= 0) {
            v1[k] = v1[i];
            i--;
            k--;
        }
    }
    return v1;
    
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(8);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(10);
    v2.push_back(12);

    displayVector(v1); // 1 2 3 0 0 0 

    displayVector(v2); // 2 5 6 

    vector<int> v = mergeTwoSortedArrays(v1,v2);

    displayVector(v); // 1 2 2 3 5 6 
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& v) {
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// time Complexity : O(n+m)
// space complexity : O(n+m)

vector<int> mergeTwoSortedArrays(vector<int>& v1, vector<int>& v2) {
    int m = v1.size();
    int n = v2.size();
    vector<int> mergedArray(m+n);
    int i = 0; // v1
    int j = 0; // v2
    int k = 0; // mergedArray

    while(i <= m-1 && j <= n-1) {
        if(v1[i] <= v2[j]) {
            mergedArray[k] = v1[i];
            i++;
            k++;
        }
        else { // v1[i] > v2[j]
            mergedArray[k] = v2[j];
            j++;
            k++;
        }
    }

    if(i == m) { // v1 is covered
        while(j <= n-1) {
            mergedArray[k] = v2[j];
            j++;
            k++;
        }
    }

    if(j == n) { // v2 is covered
        while(i <= m-1) {
            mergedArray[k] = v1[i];
            i++;
            k++;
        }
    }

    return mergedArray;
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

    displayVector(v1); // 1 4 5 8 

    displayVector(v2); // 2 3 6 7 10 12 

    vector<int> v = mergeTwoSortedArrays(v1,v2);

    displayVector(v); // 1 2 3 4 5 6 7 8 10 12 
    return 0;
}
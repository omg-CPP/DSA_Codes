#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVector(vector<int>& a) {
    for(int i = 0 ; i < a.size() ; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

void reversePart(vector<int>& v, int i, int j) {
    while(i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    return;
}

void reverse(vector<int>& v) {
    int i = 0;
    int j = v.size()-1;
    while(i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    return;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    displayVector(v);
    // 1 2 3 4 5 6

    // reverse(v.begin(), v.end()); // inbuilt reverse function
    // displayVector(v);
    // 6 5 4 3 2 1 

    displayVector(v);
    // 1 2 3 4 5 6
    
    reversePart(v,1,4);
    displayVector(v);
    // 1 5 4 3 2 6  

    reverse(v);
    displayVector(v);
    // 6 2 3 4 5 1 
    return 0;
}
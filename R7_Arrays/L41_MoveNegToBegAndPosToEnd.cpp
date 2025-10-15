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
    int i = 0;
    int j = n-1;
    while(i < j) {
        if(v[i] < 0) {
            i++;
        }   
        else if(v[j] > 0) {
            j--;
        }
        else if(v[i] > 0 && v[j] < 0) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
}

int main()
{
    // M2 - One Pass Method
    // Using Two Pointers

    vector<int> v;

    v.push_back(1);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(-4);
    v.push_back(-5);
    v.push_back(6);
    v.push_back(-3);
    v.push_back(8);

    displayVector(v); // 1 -2 3 -4 -5 6 -3 8 

    sortArrayOf01(v);

    displayVector(v); // -3 -2 -5 -4 3 6 1 8 

    return 0;
}
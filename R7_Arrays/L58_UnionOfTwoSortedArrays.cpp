#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n1+n2)
// Space Complexity : O(n1+n1) {If Space of Union vector is considered} 
// O(1) {If Space of union vector is not considered}

vector<int> unionOfArray(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) {
            if(unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else { // a[i] > b[j]
            if(unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(j < n2) {
        if(unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while(i < n1) {
        if(unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    return unionArr;
}
int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    vector<int> b = {2,3,4,4,5,11,12}; 
    vector<int> res = unionOfArray(a,b);
    cout<<"Union Array is : ";
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    // Union Array is : 1 2 3 4 5 6 7 8 9 10 11 12 
    cout<<endl;
    return 0;
}
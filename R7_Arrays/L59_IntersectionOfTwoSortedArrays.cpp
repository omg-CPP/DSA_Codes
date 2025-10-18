#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(n1+n2)
// Space Complexity : O(1)
vector<int> intersectionOfArray(vector<int>& a, vector<int>& b) {
    vector<int> intersectionArray;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2) {
        if(a[i] == b[j]) {
            intersectionArray.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] < b[j]) {
            i++;
        }
        else { // a[i] > b[j]
            j++;
        }
    }
    return intersectionArray;
}
int main()
{
    vector<int> A = {1,2,2,3,3,4,5,6};
    vector<int> B = {2,3,3,5,6,6,7};   
    vector<int> ans = intersectionOfArray(A,B);
    cout<<"Intersection Array is : ";
    for (int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // Intersection Array is : 2 3 3 5 6 
    cout<<endl;
    return 0;
}
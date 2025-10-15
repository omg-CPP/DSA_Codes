#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& v) {
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void swap(vector<int>& v, int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void sortArrayOf012(vector<int>& v) {

    int n = v.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    // 0 to low-1 = 0 // extreme left
    // low to mid-1 = 1
    // high+1 - (n-1) = 2 // extreme right

    // mid ke baare me socho
    // follow ipad air

    while(mid <= high) {
        if(v[mid] == 0) {
            // int temp = v[low];
            // v[low] = v[mid];
            // v[mid] = temp;
            swap(v,low,mid);
            low++;
            mid++;
        }
        else if(v[mid] == 1) {
            mid++;
        }
        else if(v[mid] == 2) {
            // int temp = v[high];
            // v[high] = v[mid];
            // v[mid] = temp;
            swap(v,mid,high);
            high--;
        }
    }    
}

int main()
{

    // leetcode 75
    // Sort Colors
    // M2 : One Pass Solution
    // Three Pointer Approach
    // Dutch Flag Algorithm
    // Time Complexity : O(n)
    // Space Complexity : O(1)

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
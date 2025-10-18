// Leetcode : 283
#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(n)
void moveZeroesNaive(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] != 0) { // non-zero element
            ans.push_back(arr[i]);
            count++;
        }
    }
    for(int i = count ; i < n ; i++) {
        ans.push_back(0);
    }
    for(int i = 0 ; i < n ; i++) {
        arr[i] = ans[i];
    }
}

// idea is to find first 0 and than swap it with next non-zero element 
// with moving forward the pointer j one step as the next place would  be a zero only 
// it had been swapped previously to become 0 or had been a 0 only 
// T.C. = O(n)
// S.C. = O(1)
// Optimal Approach
void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    int j = -1;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }
    // No zero found
    if(j == -1) {
        return;
    }
    for(int i = j+1 ; i < n ; i++) {
        if(arr[i] != 0) {
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {0,6,0,7,6,0,9,1};
    int n = arr.size();
    // printing array
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 0 6 0 7 6 0 9 1 
    cout<<endl;

    moveZeroes(arr);

    // printing array
    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 6 7 6 9 1 0 0 0 
    cout<<endl;
    return 0;
}






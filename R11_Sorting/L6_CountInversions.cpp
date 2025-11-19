// GFG :: Count Inversions

// Given an array of integers arr[]. 
// You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

#include <iostream>
#include <vector>
using namespace std;

// Brute Force :: TLE
// T.C. = O(n^2)
// S.C. = O(1)
int inversionCountNaive(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i < j && arr[i] > arr[j]) {
                ans++;
            }
        }
    }
    return ans;
}

// Brute Force :: TLE
// T.C. = O(n^2)
// S.C. = O(1)
int inversionCountBetter(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(arr[i] > arr[j]) {
                ans++;
            }
        }
    }
    return ans;
}


int merge(vector<int>& arr, int lo, int mid, int hi) {
    vector<int> temp;

    // first arr = [lo...mid]
    // second arr = [mid+1...hi]
    int left = lo;
    int right = mid+1;

    int count = 0;
    while(left <= mid && right <= hi) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else { // arr[left] > arr[right]
            temp.push_back(arr[right]);
            count += mid-left+1;
            right++;
        }
    }

    if(left == mid+1) {
        while(right <= hi) {
            temp.push_back(arr[right]);
            right++;
        }
    }

    if(right == hi+1) {
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    }

    for(int i = lo ; i <= hi ; i++) {
        arr[i] = temp[i-lo];
    }

    return count;
}

int mS(vector<int>& arr, int lo, int hi) {
    int cnt = 0;
    int n = arr.size();
    if(lo == hi) {
        return cnt;
    }
    int mid = (lo + hi) / 2;
    cnt += mS(arr,lo,mid);
    cnt += mS(arr,mid+1,hi);
    cnt += merge(arr,lo,mid,hi);
    return cnt;
}

// Optimal Approach
// T.C. = O(nlogn)
// S.C. = O(n)
int inversionCount(vector<int>& arr) {
    int n = arr.size();
    int count = mS(arr,0,n-1);
    return count;
}


int main()
{
    vector<int> arr = {5,3,2,4,1};
    cout<<inversionCountNaive(arr)<<endl; // 8
    cout<<inversionCountBetter(arr)<<endl; // 8
    cout<<inversionCount(arr)<<endl; // 8
    return 0;
}
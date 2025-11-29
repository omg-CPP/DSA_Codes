// GFG

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(m+n) 
// S.C. = O(m+n)
int kthElementBruteForce(vector<int>& a, vector<int>& b, int z) {
    int m = a.size();
    int n = b.size();
    vector<int> c(m+n,0);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n) {
        if(a[i] <= b[j]) {
            c[k] = a[i];
            i++;
            k++;
        }
        else { // a[i] > b[j]
            c[k] = b[j];
            j++;
            k++;
        }
    }
    if(i == m) {
        while(j < n) {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    if(j == n) {
        while(i < m) {
            c[k] = a[i];
            i++;
            k++;
        }
    }
    return c[z-1];
}

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size();
    int n2 = b.size();
    if(n1 > n2) {
        return kthElement(b,a,k);
    }
    int lo = max(k-n2,0);
    int hi = min(k,n1);
    int left = k;
    int n = n1 + n2;
    while(lo <= hi) {
        int mid1 = lo + (hi-lo) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1-1 >= 0) l1 = a[mid1-1];
        if(mid2-1 >= 0) l2 = b[mid2-1];
        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 != 0) {
                return max(l1,l2);
            }
        }
        else if(l1 > r2) {
            hi = mid1 - 1;
        }
        else { // l2 > r1
            lo = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}
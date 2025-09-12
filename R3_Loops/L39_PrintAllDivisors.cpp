#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Brute/Naive Method 
// T.C. : O(n)
// S.C. : O(1)
void printDivisorsNaive(int n) {
    for(int i = 1 ; i <= n ; i++) {
        if(n % i == 0) {
            cout<<i<<" ";
        }
    }
    return;
}

// Optimal Approach :
// T.C. : O(sqrt(n))

// 36 : 1 2 3 4 6 9 12 18 36 

// 1 * 36 = 36
// 2 * 18 = 36
// 3 * 12 = 36
// 4 * 9 = 36
// 6 * 6 = 36
// --------------
// 9 * 4 = 36
// 12 * 3 = 36
// 18 * 2 = 36
// 36 * 1 = 36

void printDivisorsOptimal(int n) {
    vector<int> divisors;
    // instead of i <= sqrt(n) write i*i <= n
    for(int i = 1 ; i*i <= n ; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(n/i != i) {
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for(int i = 0 ; i < divisors.size() ; i++) {
        cout<<divisors[i]<<" ";
    }
    return;
}

int main()
{
    int n; // n = 36
    cout<<"Enter number : ";
    cin>>n;
    printDivisorsNaive(n);
    // 1 2 3 4 6 9 12 18 36 
    cout<<endl;
    printDivisorsOptimal(n);
    // 1 2 3 4 6 9 12 18 36 
    return 0;
}

// Enter number : 56
// 1 2 4 7 8 14 28 56 
// 1 2 4 7 8 14 28 56 
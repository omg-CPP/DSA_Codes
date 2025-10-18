#include <iostream>
#include <vector>
using namespace std;
int missingNumberBruteForce(vector<int>& a, int N) {
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < N-1; j++) {
            if (a[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
    return -1;
}

int missingNumberOptimal(vector<int>& a, int N) {
    int sum = (N*(N+1))/2;
    int sumArr = 0;
    for(int i = 0 ; i < N-1 ; i++) {
        sumArr += a[i];
    }
    int missingNumber = sum-sumArr;
    return missingNumber;
}

int missingNumberOptimalXOR(vector<int>& a, int N) {
    int xor1 = 0;
    int xor2 = 0;

    // Two Loops
    // for(int i = 1 ; i <= N ; i++) {
    //     xor1 = xor1 ^ i;
    // }
    // for(int i = 0 ; i < N-1 ; i++) {
    //     xor2 = xor2 ^ a[i];
    // }

    // Single Loop
    for(int i = 0 ; i < N-1 ; i++) {
        xor1 = xor1 ^ (i+1); // XOR up to 1 -> (N-1)
        xor2 = xor2 ^ a[i]; // XOR of array elements
    }
    xor1 = xor1 ^ N; // XOR to N

    int missingNumber = xor1 ^ xor2;
    return missingNumber; // the missing number
}

int main()
{
    int N = 5; // Total numbers : (1 - 5)
    vector<int> a = {1,2,4,5};
    int ans = missingNumberBruteForce(a,N);
    cout<<"The missing number is : "<<ans<<endl;
    // The missing number is : 3

    int res = missingNumberOptimal(a,N);
    cout<<"The missing number is : "<<res<<endl;
    // The missing number is : 3

    int sol = missingNumberOptimalXOR(a,N);
    cout<<"The missing number is : "<<sol<<endl;
    // The missing number is : 3
    return 0;
}
#include <iostream>
using namespace std;

// 3^8 = 3^4 * 3^4
// 3^4 = 3^2 * 3^2
// 3^2 = 3^1 * 3^1

int pow(int x, int n) {
    // base case
    if(n == 1) {
        return x;
    }
    // int ans = pow(x,n/2) * pow(x,n/2);
    int ans = pow(x,n/2);
    if(n % 2 != 0) { // power -> odd
        return x * ans * ans;
    }
    return ans * ans;
}

int main()
{
    // Logarthmic Time Complexity : O(logn)
    // Space Complexity : O(logn)
    int x; // base
    cout<<"Enter base : ";
    cin>>x;
    int n; // power
    cout<<"Enter power : ";
    cin>>n;
    cout<<pow(x,n)<<endl; 
    return 0;
}

// Enter base : 3
// Enter power : 6
// 729

// Enter base : 3
// Enter power : 8
// 6561

// Enter base : 3
// Enter power : 5
// 243

// Enter base : 2
// Enter power : 5
// 32
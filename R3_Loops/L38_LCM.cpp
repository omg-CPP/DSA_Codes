#include <iostream>
using namespace std;
// LCM -> Least Common Multiple

void LCM_BruteForce(int a, int b) {
    // No of iterations = a*b - max(a,b) + 1
    // Time Complexity : O(a*b - max(a,b)) 
    // LCM of 3 and 7 
    // 7 ----- 21
    // max(a,b) ----- a*b
    int maxi = max(a,b);
    while(true) {
        if((maxi % a == 0) && (maxi % b == 0)) {
            cout<<"LCM of "<<a<<" and "<<b<<" is : "<<maxi<<endl;
            break;
        }
        maxi++;
    }
    return;
}

int GCD_Optimal(int a, int b) {
    // Gabriel Lame Algorithm
    // Log Time Complexity : O(log(min(a,b))
    // a/2 or b/2 > (a%b) or (b%a)
    // 12 8
    // 4 8
    // 4 0
    // 4
    while(a != 0 && b != 0) {
        if(a > b) {
            a = a % b;
        }
        else { // a < b
            b = b % a;
        }
    }
    // return non-zero out of a or b
    if(a != 0) {
        return a;
    }
    else { // b != 0
        return b;
    }
}

int LCM_optimal(int a, int b) {
    // Log Time Complexity : O(log(min(a,b))
    // LCM(a,b) * GCD(a,b) = a * b
    int lcm = (a*b) / GCD_Optimal(a,b);
    return lcm;
}

int main()
{
    int a;
    cout<<"Enter num 1 : ";
    cin>>a;
    int b;
    cout<<"Enter num 2 : ";
    cin>>b;
    LCM_BruteForce(a,b);

    int ans = LCM_optimal(a,b);
    cout<<ans<<endl;
    return 0;
}

// Enter num 1 : 7
// Enter num 2 : 3
// LCM of 7 and 3 is : 21
// 21

// Enter num 1 : 12
// Enter num 2 : 8
// LCM of 12 and 8 is : 24
// 24
#include <iostream>
using namespace std;
// GCD -> Greatest Common Divisor
// HCF -> Highest Common Factor
// Factor or Divisor : Num gets perfectely divide i.e. rem = 0

void GCD_BruteForce(int a, int b) {
    // Brute Force Approach
    // Time Complexity : O(min(a,b))
    // GCD (20,15) : 15,14,13,12,11,10,9,8,7,6,5 : 11 steps
    int mini = min(a,b);
    for(int i = mini ; i >= 1 ; i--) {
        if((a % i == 0) && (b % i == 0)) {
            cout<<i<<" is the GCD or the HCF"<<endl;
            break;
        }
    }
    return;
}

int GCD_Better(int a, int b) {
    // Euclid GCD
    // More Efficient Solution
    // Time Complexity : O(max(a,b)) : {13,1} : 13 iterations
    // Euclid's Algorithm : 3 steps
    // a = 20 and b = 15 => GCD = 5
    // a > b => a = a-b = 20-15 = 5
    // a = 5 and b = 15
    // b > a => b = b-a = 15-5 = 10
    // a = 5 and b = 10
    // b > a => b = b-a = 10-5 = 5
    // a = 5 and b = 5
    // return a or b
    while(a != b) {
        if(a > b) {
            a = a - b;
        }
        else { // a < b
            b = b - a;
        }
    }
    return a;
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

int main()
{
    int a;
    cout<<"Enter num 1 : ";
    cin>>a;
    int b;
    cout<<"Enter num 2 : ";
    cin>>b;

    GCD_BruteForce(a,b);

    int hcf = GCD_Better(a,b);
    cout<<hcf<<endl; // 5

    int res = GCD_Optimal(a,b);
    cout<<res<<endl; // 5
    return 0;
}

// Enter num 1 : 20
// Enter num 2 : 15
// 5 is the GCD or the HCF

// Enter num 1 : 17
// Enter num 2 : 13
// 1 is the GCD or the HCF

// Enter num 1 : 1733
// Enter num 2 : 1333
// 1 is the GCD or the HCF
// 1
// 1

// Enter num 1 : 12
// Enter num 2 : 8
// 4 is the GCD or the HCF
// 4
// 4
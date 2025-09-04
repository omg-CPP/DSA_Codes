#include <iostream>
using namespace std;

// T.C. : O(n)
bool isPrime(int num) {
    bool flag = true; // means prime
    for(int i = 2 ; i <= num-1 ; i++) {
        // 'i' is a factor of 'n'
        if(num % i == 0) {
            flag = false; // means composite
            break;
        }
    }
    return flag;
}

int main()
{
    // break -> Keyword to finish/terminate a loop
    // Composite Numbers : Min 1 factor from 2 to n-1
    // Prime Numbers : Number divisible by 1 and itself only
    // Prime Numbers : 2,3,5,7,11,13,17,19,---
    // 1 is Neither Prime Nor Composite
    // 2 is the only even prime number
    int n;
    cout<<"Enter the num : ";
    cin>>n;
    if(n <= 0) {
        cout<<"Invalid Choice!!"<<endl;
    }
    else if(n == 1) {
        cout<<"Neither Prime Nor Composite"<<endl;
    }
    else { // n > 1
        if(isPrime(n) == true) {
            cout<<"Prime Number"<<endl;
        }
        else { 
            cout<<"Composite Number"<<endl;
        }
    }
    return 0;
}

// Enter the num : -5
// Invalid Choice!!

// Enter the num : 0
// Invalid Choice!!

// Enter the num : 1
// Neither Prime Nor Composite

// Enter the num : 2
// Prime Number

// Enter the num : 5
// Prime Number

// Enter the num : 6
// Composite Number
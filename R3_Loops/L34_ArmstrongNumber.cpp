#include <iostream>
using namespace std;
int main()
{
    // An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits. For example, 153 is an Armstrong number because 1^3 + 5^3 + 3^3 = 153

    int n;
    cout<<"Enter num : ";
    cin>>n;
    int temp = n;
    int sum = 0;
    int ld;
    while(n != 0) {
        ld = n % 10;
        sum = sum + (ld*ld*ld);
        n = n / 10;
    }
    if(sum == temp) {
        cout<<"Armstrong Number"<<endl;
    }
    else {
        cout<<"Not a Armstrong Number"<<endl;
    }
    return 0;
}

// Enter num : 153
// Armstrong Number

// Enter num : 456
// Not a Armstrong Number
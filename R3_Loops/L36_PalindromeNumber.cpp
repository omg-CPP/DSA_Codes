#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int temp = n;
    int ld;
    int rev = 0;
    while(temp != 0) {
        ld = temp % 10;
        rev = (rev * 10) + ld;
        temp = temp / 10;
    }
    if(rev == n) {
        cout<<"Palindrome Number"<<endl;
    }
    else {
        cout<<"Not a Palindrome Number"<<endl;
    }
    return 0;
}

// Enter n : 12421
// Palindrome Number

// Enter n : 5689
// Not a Palindrome Number
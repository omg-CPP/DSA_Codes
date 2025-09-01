#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;

    if((n % 3 == 0 || n % 5 == 0) && (n % 15 != 0)) {
        cout<<"Divisible by 3 or 5 but not by 15"<<endl;
    }
    else {
        cout<<"Invalid Condition"<<endl;
    }
    return 0;
}

// Enter n : 9
// Divisible by 3 or 5 but not by 15


// Enter n : 25
// Divisible by 3 or 5 but not by 15


// Enter n : 60
// Invalid Condition

// Hierarchy : && > ||
// T & T = T     T | T = T
// T & F = F     T | F = T
// F & T = F     F | T = T
// F & F = F     F | F = F
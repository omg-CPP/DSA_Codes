#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    if(n % 3 == 0 || n & 5 == 0) {
        cout<<"Number Divisible By 3 or 5"<<endl;
    }
    else {
        cout<<"Number is Not Divisible By 3 or 5"<<endl;
    }
    return 0;
}

// Enter n : 15
// Number Divisible By 3 or 5

// Enter n : 28
// Number is Not Divisible By 3 or 5
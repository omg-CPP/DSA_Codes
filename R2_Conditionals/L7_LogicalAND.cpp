#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    if(n > 99 && n < 1000) {
        cout<<"A Three Digit Number"<<endl;
    }
    else {
        cout<<"Not A Three Digit Number"<<endl;
    }
    return 0;
}

// Enter n : 888
// A Three Digit Number

// Enter n : 54
// Not A Three Digit Number
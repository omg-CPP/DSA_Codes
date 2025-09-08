#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int sum = 0;
    int ld;
    while(num != 0) {
        ld = num % 10;
        sum = sum + ld;
        num = num / 10;
    }
    cout<<"The Sum of Digits of the number is : "<<sum<<endl;
    return 0;
}

// Enter the number : 1234
// The Sum of Digits of the number is : 10

// Enter the number : 5187
// The Sum of Digits of the number is : 21
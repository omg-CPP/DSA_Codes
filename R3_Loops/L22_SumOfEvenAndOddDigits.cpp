#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int sumEven = 0;
    int sumOdd = 0;
    int ld;
    while(num != 0) {
        ld = num % 10;
        if(ld % 2 == 0) {
            sumEven += ld;
        }
        else { // ld % 2 != 0
            sumOdd += ld;
        }
        num = num / 10;
    }
    cout<<"Sum of Even Digits : "<<sumEven<<endl;
    cout<<"Sum of Odd Digits : "<<sumOdd<<endl;
    return 0;
}

// Enter the number : 12345
// Sum of Even Digits : 6
// Sum of Odd Digits : 9
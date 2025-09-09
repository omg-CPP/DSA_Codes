#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int temp = num;
    int rev = 0;
    int ld;
    while(num != 0) {
        ld = num % 10;
        rev = (rev * 10) + ld;
        num = num / 10;
    }
    int sum = temp + rev;
    cout<<"Sum of "<<temp<<" and "<<rev<<" is : "<<sum<<endl;
    return 0;
}

// Enter the number : 1234
// Sum of 1234 and 4321 is : 5555
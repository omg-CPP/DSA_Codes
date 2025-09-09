#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int rev = 0;
    int ld;
    while(num != 0) {
        ld = num % 10;
        rev = (rev * 10) + ld;
        num = num / 10;
    }
    cout<<"The Reverse of the number is : "<<rev<<endl;
    return 0;
}

// Enter the number : 1234
// The Reverse of the number is : 4321

// Enter the number : 48956
// The Reverse of the number is : 65984
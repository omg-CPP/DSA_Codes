#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int count = 0;
    while(num != 0) {
        num = num / 10;
        count++;
    }
    cout<<"The Count of Digits of the Number is : "<<count<<endl;
    return 0;
}

// Enter the number : 12345
// The Count of Digits of the Number is : 5

// Enter the number : 87456
// The Count of Digits of the Number is : 5

// Enter the number : 1234
// The Count of Digits of the Number is : 4
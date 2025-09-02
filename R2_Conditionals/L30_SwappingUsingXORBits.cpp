#include <iostream>
using namespace std;
int main()
{
    int num1 = 13; // 1 1 0 1
    int num2 = 7;  // 0 1 1 1

    cout<<"Before Swapping"<<endl;
    cout<<num1<<" "<<num2<<endl; // 13 7

    num1 = num1 ^ num2;  // 1 0 1 0 -> 10
    num2 = num1 ^ num2;  // 1 1 0 1 -> 13
    num1 = num1 ^ num2;  // 0 1 1 1 ->  7

    cout<<"After Swapping"<<endl;
    cout<<num1<<" "<<num2<<endl; // 7 13
    return 0;
}
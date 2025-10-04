#include <iostream>
using namespace std;

void find(int n, int* ptr1, int* ptr2) {
    *ptr2 = n%10;
    while(n > 9) {
        n = n/10;
    }
    *ptr1 = n;
    return;
}
int main()
{
    int num;
    cout<<"Enter num : ";
    cin>>num;
    int firsrDigit, lastDigit;
    int* ptr1 = &firsrDigit;
    int* ptr2 = &lastDigit;
    find(num, ptr1, ptr2);
    cout<<firsrDigit<<"  "<<lastDigit<<endl;
    return 0;
}

// Enter num : 124568
// 1  8
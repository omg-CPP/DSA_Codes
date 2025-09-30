#include <iostream>
using namespace std;
int factorial(int num) {
    int fact = 1;
    for(int i = 1 ; i <= num ; i++) {
        fact = fact*i;
    }
    return fact;
}
int main()
{
    int num;
    cout<<"Enter num : ";
    cin>>num;
    for(int i = 1 ; i <= num ; i++) {
        cout<<factorial(i)<<" ";
    }
    return 0;
}

// Enter num : 6
// 1 2 6 24 120 720 
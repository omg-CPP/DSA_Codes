#include <iostream>
using namespace std;

// without uing any paramater
int sum1ToN(int n) {
    if(n == 0) {
        return 0;
    }
    int sum = n + sum1ToN(n-1);
    return sum;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<sum1ToN(n)<<endl;
    return 0;
}

// Enter n : 5
// 15

// Enter n : 10
// 55
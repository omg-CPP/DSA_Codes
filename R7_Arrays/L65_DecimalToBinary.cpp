#include <iostream>
using namespace std;

int decToBinary(int decNum) {
    int ans = 0;
    int pow = 1; // 10^0
    while(decNum > 0) {
        int rem = decNum % 2;
        ans = ans + (rem * pow);
        pow = pow * 10;
        decNum = decNum / 2;
    }
    return ans;
}
int main()
{
    cout<<decToBinary(50)<<endl; // 110010
    cout<<decToBinary(42)<<endl; // 101010
    cout<<decToBinary(5)<<endl; // 101
    cout<<decToBinary(7)<<endl; // 111
    for(int i = 1 ; i <= 10 ; i++) {
        cout<<decToBinary(i)<<endl;
    }
    // 1
    // 10
    // 11
    // 100
    // 101
    // 110
    // 111
    // 1000
    // 1001
    // 1010
    return 0;
}

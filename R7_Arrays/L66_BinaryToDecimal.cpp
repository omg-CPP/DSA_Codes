#include <iostream>
using namespace std;

int binToDecimal(int binNum) {
    int ans = 0;
    int pow = 1; // 2^0
    while(binNum > 0) {
        int rem = binNum % 10;
        ans = ans + (rem * pow);
        pow = pow * 2;
        binNum = binNum /10;
    }
    return ans;
}
int main()
{
    cout<<binToDecimal(101010)<<endl; // 42
    cout<<binToDecimal(110010)<<endl; // 50
    return 0;
}

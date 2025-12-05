#include <iostream>
using namespace std;

// parameterised
void sum1ToN(int sum, int n) {
    if(n == 0) {
        cout<<sum<<endl;
        return;
    }
    sum1ToN(sum+n,n-1);
    return;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    sum1ToN(0,n);
    return 0;
}

// Enter n : 5 
// 15

// 0,5 -> 5,4 -> 9,3 -> 12,2 -> 14,1 -> 15,0
#include <iostream>
using namespace std;

int factorialOfFirstNNatural(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    int factorial = n * factorialOfFirstNNatural(n-1);
    return factorial;
}
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i = 0 ; i <= n ; i++) {
        cout<<i<<"! : "<<factorialOfFirstNNatural(i)<<endl;
    }
    return 0;
}

// Enter n : 7
// 0! : 1
// 1! : 1
// 2! : 2
// 3! : 6
// 4! : 24
// 5! : 120
// 6! : 720
// 7! : 5040
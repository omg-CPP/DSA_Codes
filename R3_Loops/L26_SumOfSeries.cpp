#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 1+2+3+4+5+6+-----+n terms
    int sum = 0;
    for(int i = 1 ; i <= n ; i++) {
        sum += i;
    }
    cout<<"Sum of the Series is : "<<sum<<endl;
    return 0;
}

// Enter no of terms : 5
// Sum of the Series is : 15
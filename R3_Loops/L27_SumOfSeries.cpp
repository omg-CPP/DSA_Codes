#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 1-2+3-4+5-6+-----+n terms
    int sum = 0;
    for(int i = 1 ; i <= n ; i++) {
        if(i % 2 != 0) {
            sum += i;
        }
        else { // i % 2 == 0
            sum -= i;
        }
    }
    cout<<"Sum is : "<<sum<<endl;
    return 0;
}

// Enter no of terms : 7
// Sum is : 4
#include <iostream>
using namespace std;
int main()
{
    for(int i = 1 ; i <= 500 ; i++) {
        int sum = 0;
        int temp = i;
        int ld;
        while(temp != 0) {
            ld = temp % 10;
            sum = sum + (ld*ld*ld);
            temp = temp / 10;
        }
        if(sum == i) {
            cout<<"Armstrong Number : "<<i<<endl;
        }
    }
    return 0;
}

// Armstrong Number : 1
// Armstrong Number : 153
// Armstrong Number : 370
// Armstrong Number : 371
// Armstrong Number : 407
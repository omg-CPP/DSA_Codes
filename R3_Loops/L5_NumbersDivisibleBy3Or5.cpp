#include <iostream>
using namespace std;
int main()
{
    for(int i = 1 ; i <= 100 ; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            cout<<i<<" ";
        }
    }
    // 3 5 6 9 10 12 15 18 20 21 24 25 27 30 33 35 36 39 40 42 45 48 50 51 54 55 57 60 63 65 66 69 70 72 75 78 80 81 84 85 87 90 93 95 96 99 100 
    cout<<endl<<endl;

    for(int i = 1 ; i <= 100 ; i++) {
        if(i % 3 == 0 && i % 5 == 0) {
            cout<<i<<" ";
        }
    }
    // 15 30 45 60 75 90 
    cout<<endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    // Will not run
    for(int i = 11 ; i <= 10 ; i++) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Will not run
    int i = 11;
    while(i <= 10) {
        cout<<i<<" ";
        i++;
    }
    cout<<endl;

    // Will work for one time
    int j = 11;
    do {
        cout<<j<<" ";
        j++;
    }
    while(j <= 10);
    // 11 
    cout<<endl; 
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n500, n200, n100, n50, n20, n10;
    int amount;
    cout<<"Enter amount : ";
    cin>>amount;

    if(amount >= 500) {
        n500 = amount/500;
        cout<<"500 notes : "<<n500<<endl;
        amount = amount - (n500*500);
    }
    if(amount >= 200) {
        n200 = amount/200;
        cout<<"200 notes : "<<n200<<endl;
        amount = amount - (n200*200);
    }
    if(amount >= 100) {
        n100 = amount/100;
        cout<<"100 notes : "<<n100<<endl;
        amount = amount - (n100*100);
    }
    if(amount >= 50) {
        n50 = amount/50;
        cout<<"50 notes : "<<n50<<endl;
        amount = amount - (n50*50);
    }
    if(amount >= 20) {
        n20 = amount/20;
        cout<<"20 notes : "<<n20<<endl;
        amount = amount - (n20*20);
    }
    if(amount >= 10) {
        n10 = amount/10;
        cout<<"10 notes : "<<n10<<endl;
        amount = amount - (n10*10);
    }
    return 0;
}

// Enter amount : 3580
// 500 notes : 7
// 50 notes : 1
// 20 notes : 1
// 10 notes : 1
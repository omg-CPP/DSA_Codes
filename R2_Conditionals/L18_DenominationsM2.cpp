// How it works:
// You wrote switch(1) — so it's always starting at case 1.

// In C++, if you don’t put a break; statement at the end of a case, execution falls through to the next case.

// So here, after executing case 1, it goes to case 2, then case 3, and so on — effectively making it act like a series of sequential statements (like a loop-less chained sequence).

// That’s why it works as a single-pass denomination calculator.

#include <iostream>
using namespace std;
int main()
{
    int n2000,n500,n200,n100,n50,n20,n10,n5,n2,n1;
    int amount;
    cout<<"Enter amount : ";
    cin>>amount;

    switch(1) { 
        case 1 :
                n2000 = amount/2000;
                cout<<"2000 notes : "<<n2000<<endl;
                amount -= n2000*2000;

        case 2 :
                n500 = amount/500;
                cout<<"500 notes : "<<n500<<endl;
                amount -= n500*500;

        case 3 :
                n200 = amount/200;
                cout<<"200 notes : "<<n200<<endl;
                amount -= n200*200;

        case 4 : 
                n100 = amount/100;
                cout<<"100 notes : "<<n100<<endl;
                amount -= n100*100;

        case 5 : 
                n50 = amount/50;
                cout<<"50 notes : "<<n50<<endl;
                amount -= n50*50;

        case 6 : 
                n20 = amount/20;
                cout<<"20 notes : "<<n20<<endl;
                amount -= n20*20;
            
        case 7 : 
                n10 = amount/10;
                cout<<"10 notes : "<<n10<<endl;
                amount -= n10*10;

        case 8 : 
                n5 = amount/5;
                cout<<"5 notes : "<<n5<<endl;
                amount -= n5*5;

        case 9 :
                n2 = amount/2;
                cout<<"2 notes : "<<n2<<endl;
                amount -= n2*2;

        case 10 : 
                n1 = amount/1;
                cout<<"1 notes : "<<n1<<endl;
                amount -= n1*1;
    }
    return 0;
}

// Enter amount : 3888

// 2000 notes : 1
// 500 notes : 3
// 200 notes : 1
// 100 notes : 1
// 50 notes : 1
// 20 notes : 1
// 10 notes : 1
// 5 notes : 1
// 2 notes : 1
// 1 notes : 1
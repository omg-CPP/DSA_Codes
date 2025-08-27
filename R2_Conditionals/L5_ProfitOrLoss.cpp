#include <iostream>
using namespace std;
int main()
{
    float cp;
    cout<<"Enter cost price : ";
    cin>>cp;
    float sp;
    cout<<"Enter selling price : ";
    cin>>sp;

    if(cp > sp) {
        cout<<"LOSS"<<endl;
        float loss = cp - sp;
        cout<<"Loss : "<<loss<<endl;
        cout<<"Loss Percent : "<<(loss/cp)*100<<endl;
    }
    else if(cp < sp) {
        cout<<"PROFIT"<<endl;
        float profit = sp - cp;
        cout<<"Profit : "<<profit<<endl;
        cout<<"Profit Percent : "<<(profit/cp)*100<<endl;
    }
    else { // cp == sp
        cout<<"No Profit No Loss"<<endl;
    }
    return 0;
}

// Enter cost price : 100
// Enter selling price : 120
// PROFIT
// Profit : 20
// Profit Percent : 20
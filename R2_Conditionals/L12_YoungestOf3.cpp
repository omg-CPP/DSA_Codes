#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter Ram's age : ";
    cin>>a;
    cout<<"Enter Shyam's age : ";
    cin>>b;
    cout<<"Enter Ajay's age : ";
    cin>>c;

    if(a < b && a < c) {
        cout<<"Ram is the youngest"<<endl;
    }
    else if(b < a && b < c) {
        cout<<"Shyam is the youngest"<<endl;
    }
    else {
        cout<<"Ajay is the youngest"<<endl;
    }
    return 0;
}

// Enter Ram's age : 12
// Enter Shyam's age : 45
// Enter Ajay's age : 65
// Ram is the youngest
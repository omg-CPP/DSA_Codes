#include <iostream>
using namespace std;
int main()
{
    int m;
    cout<<"Enter marks : ";
    cin>>m;

    if(m >= 90) {
        cout<<"O"<<endl;
    }
    else if(m >= 80) {
        cout<<"A"<<endl;
    }
    else if(m >= 70) {
        cout<<"B"<<endl;
    }
    else if(m >= 60) {
        cout<<"C"<<endl;
    }
    else if(m >= 50) {
        cout<<"D"<<endl;
    }
    else if(m >= 40) {
        cout<<"E"<<endl;
    }
    else { // m < 40
        cout<<"FAIL"<<endl;
    }
    return 0;
}

// Enter marks : 86
// A
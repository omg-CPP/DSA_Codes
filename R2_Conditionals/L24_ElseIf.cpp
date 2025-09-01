#include <iostream>
using namespace std;
int main()
{
    int p;
    cout<<"Enter percentage : ";
    cin>>p;

    if(p >= 90) {
        cout<<"Excellent"<<endl;
    }
    else if(p >= 80) {
        cout<<"Very Good"<<endl;
    }
    else if(p >= 70) {
        cout<<"Good"<<endl;
    }
    else if(p >= 60) {
        cout<<"Can Do Better"<<endl;
    }
    else if(p >= 50) {
        cout<<"Average"<<endl;
    }
    else if(p >= 40) {
        cout<<"Below Average"<<endl;
    }
    else { // p < 40
        cout<<"FAIL"<<endl;
    }
    return 0;
}

// Enter percentage : 58
// Average

// Enter percentage : 91
// Excellent
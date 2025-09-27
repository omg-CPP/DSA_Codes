#include <iostream>
using namespace std;
// Basics of Functions
void printPattern(int t) { // parameter/ argument
    for(int i = 1 ; i <= t ; i++) {
        for(int j = 1 ; j <= i ; j++) {
            cout<<"* ";
        }
        cout<<"\n";
    }
}
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    printPattern(a); // 3
    cout<<"Hello World"<<endl;
    printPattern(b); // 4
    cout<<"Hello PW"<<endl;
    printPattern(c); // 5
    return 0;
}


// 3 4 5
// * 
// * * 
// * * * 
// Hello World
// * 
// * * 
// * * * 
// * * * * 
// Hello PW
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
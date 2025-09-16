#include <iostream>
using namespace std;
int main()
{
    int l;
    cout<<"Enter length : "; // columns
    cin>>l;
    int b;
    cout<<"Enter breadth : "; // rows
    cin>>b;
    for(int i = 1 ; i <= b ; i++) {
        for(int j = 1 ; j <= l ; j++) {
            if(i == 1 || i == b || j == 1 || j == l) {
                cout<<"* ";
            }
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// Enter length : 6
// Enter breadth : 4
// * * * * * * 
// *         * 
// *         * 
// * * * * * * 
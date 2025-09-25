#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; // n : odd
    cin>>n;
    int nst = 1;
    int nsp = n-1;
    int mid = n/2 + 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        if(i < mid)
        {
            nsp -= 2;
            nst++;
        }
        else
        {
            nsp += 2;
            nst--;
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 7
// *             * 
// * *         * * 
// * * *     * * * 
// * * * * * * * * 
// * * *     * * * 
// * *         * * 
// *             * 
#include <iostream>
using namespace std;

void print(int n) {
    if(n == 0) {
        return;
    }
    cout<<"Good Morning"<<endl;
    print(n-1);
}
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    print(n);
    return 0;
}

// Enter n : 4
// Good Morning
// Good Morning
// Good Morning
// Good Morning
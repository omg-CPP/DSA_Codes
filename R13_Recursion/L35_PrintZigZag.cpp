#include <iostream>
using namespace std;

void printZigZag(int n) {
    if(n == 0) {
        return;
    }
    cout<<n;
    printZigZag(n-1);
    cout<<n;
    printZigZag(n-1);
    cout<<n;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        printZigZag(i);
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// 111
// 211121112
// 321112111232111211123
// 432111211123211121112343211121112321112111234
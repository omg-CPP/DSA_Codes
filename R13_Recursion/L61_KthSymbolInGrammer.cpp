#include <iostream>
using namespace std;

// T.C. = O(n)

int kthGrammar(int n, int k) {
    if(n == 1) {
        return 0;
    }
    if(k % 2 == 0) { // even -> flip ans, k/2
        int prevAns = kthGrammar(n-1,k/2);
        if(prevAns == 0) {
            return 1;
        }
        else { // prevAns = 1
            return 0;
        }
    }
    else { // k % 2 != 0 // odd -> same ans, k/2 + 1
        int prevAns =  kthGrammar(n-1,k/2 + 1);
        return prevAns;
    }
}

int main()
{
    int n = 4;
    int k = 6;
    cout<<kthGrammar(n,k)<<endl; // 0
    return 0;
}
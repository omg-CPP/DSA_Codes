#include <iostream>
#include <climits>
using namespace std;

int bestClosingTime(string customers) {
    int n = customers.length();
    int pre[n+1]; // No of No before Kth hour
    int suf[n+1]; // No of yes after and including Kth hour
    pre[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        pre[i] = pre[i-1] + ((customers[i-1] == 'N') ? 1 : 0);
    }

    // print : prefix
    for(int i = 0 ; i <= n ; i++) {
        cout<<pre[i]<<" ";
    }
    cout<<endl;

    suf[n] = 0;
    for(int i = n-1 ; i >= 0 ; i--) {
        suf[i] = suf[i+1] + ((customers[i] == 'Y') ? 1 : 0);
    }

    // print : suffix
    for(int i = 0 ; i <= n ; i++) {
        cout<<suf[i]<<" ";
    }
    cout<<endl;

    // penalty array as pre only
    int minPen = n;
    for(int i = 0 ; i <= n ; i++) {
        pre[i] = pre[i] + suf[i];
        int pen = pre[i];
        minPen = min(minPen,pen);
    }

    // print : prefix as penalty
    for(int i = 0 ; i <= n ; i++) {
        cout<<pre[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i <= n ; i++) {
        if(pre[i] == minPen) {
            // returning the ith hour for minimum penalty
            return i;
        }
    }
    return n;
}

int main()
{
    string s = "NYNNNYYN";
    int ans = bestClosingTime(s);
    cout<<ans<<endl;
    return 0;
}
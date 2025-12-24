#include <iostream>
using namespace std;

string helper(string org, int k, string ans) {
    int n = org.size();
    // base case 
    if(n == 1) {
        ans = ans + org;
        return ans;
    }
    // (n-1)!
    int fact = 1;
    for(int i = 1 ; i <= n-1 ; i++) {
        fact = fact * i;
    }

    int idx = k/fact;
    if(k % fact == 0) {
        idx--;
    }

    char ch = org[idx];
    string left = org.substr(0,idx);
    string right = org.substr(idx+1);
    int q = 1;
    if(k % fact == 0) {
        q = fact;
    }
    else if((k % fact != 0 && k > fact) || (k < fact)) {
        q = k % fact;
    }
    return helper(left+right,q,ans+ch);
}

string getPermutation(int n, int k) {
    // 123 , n = 3, k = 3
    // {"123", "132", "213", "231", "312", "321"}
    string org = "";
    for(int i = 1 ; i <= n ; i++) {
        org = org + to_string(i);
    }
    return helper(org,k,"");
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int k;
    cout<<"Enter k : ";
    cin>>k;
    string ans = getPermutation(n,k);
    cout<<ans<<endl;
    return 0;
}

// Enter n : 3
// Enter k : 3
// 213

// Enter n : 4
// Enter k : 9
// 2314

// Enter n : 3
// Enter k : 1
// 123
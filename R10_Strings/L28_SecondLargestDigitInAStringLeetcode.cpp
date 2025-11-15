#include <iostream>
#include <climits>
using namespace std;

bool isDigit(char ch) {
    int x = (int)ch;
    if(x >= 48 && x <= 57) {
        return true;
    }
    return false;
}

int secondHighest(string s) {
    int n = s.length();
    int l = INT_MIN;
    int sl = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        if(isDigit(s[i]) == true) {
            if((s[i] - '0') > l) {
                sl = l;
                l = (s[i] - '0');
            }
            else if((sl < (s[i] - '0')) && ((s[i] - '0') != l)) {
                sl = (s[i] - '0');
            }
        }
    }
    if(sl == INT_MIN) {
        return -1;
    }
    return sl;
}
int main()
{
    string str = "2947578";
    int ans = secondHighest(str);
    cout<<ans<<endl; // 8
    return 0;
}
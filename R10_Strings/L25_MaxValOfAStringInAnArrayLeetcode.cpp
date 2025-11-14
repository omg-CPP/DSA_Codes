#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int maxi(int a, int b, int c) {
    if(a >= b && a >= c) {
        return a;
    }
    else if(b >= a && b >= c) {
        return b;
    }
    else {
        return c;
    }
}

bool isAlpha(char ch) {
    int x = (int)ch;
    if((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) {
        return true;
    }
    return false;
}

bool isDigit(char ch) {
    int x = (int)ch;
    if(x >= 48 && x <= 57) {
        return true;
    }
    return false;
}

int maximumValue(vector<string>& strs) {
    int n = strs.size();
    int sum = 0;
    int res = 0;
    int len = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < strs[i].length() ; j++) {
            if(isAlpha(strs[i][j]) == true) {
                len = strs[i].size();
                res = maxi(res,sum,len);
                sum = 0;
                len = 0;
                break;
            }

            while(isDigit(strs[i][j]) == true) {
                sum = (sum * 10) + ((int)(strs[i][j]) - (int)('0'));
                j++;
                if(isAlpha(strs[i][j])) {
                    sum = 0;
                    len = strs[i].size();
                    break;
                }
            }
            res = maxi(res,sum,len);
            sum = 0;
            len = 0;
        }
    }
    return res;
}

int main()
{
    vector<string> str = {"alic3","bob","3","4","00000"};
    int ans = maximumValue(str);
    cout<<ans<<endl; // 5
    return 0;
}
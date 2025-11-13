#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the string : ";
    getline(cin,str);
    int len = str.length();
    int count = 0;
    for(int i = 0 ; i < len ; i++) {
        if(len == 1) {
            break;
        }
        if(len == 2 && str[0] != str[1]) {
            count = 1;
            break;
        }
        if(i == 0) {
            if(str[i] != str[i+1]) {
                count++;
            }
        }
        else if(i == len-1) {
            if(str[i] != str[i-1]) {
                count++;
            }
        }
        else if(str[i] != str[i-1] && str[i] != str[i+1]) {
            count++;
        }
    }
    cout<<count<<endl;
    // Enter the string : abbcdeffghh
    // 5

    // Enter the string : a
    // 0

    // Enter the string : ab
    // 1
    return 0;
}
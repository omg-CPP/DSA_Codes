#include <iostream>
using namespace std;
// if vowel
int main()
{
    string str = "raghav";
    cout<<str.size()<<endl; // 6
    int count = 0;
    int i = 0;
    // if size is not known
    while(str[i] != '\0') {
        if(str[i]  == 'a' || str[i]  == 'e' || str[i]  == 'i' || str[i]  == 'o' || str[i]  == 'u' ) {
            count++;
        }
        i++;
    }
    cout<<count<<endl; // 2

    string s;
    cout<<"Enter the String : ";
    getline(cin,s);
    cout<<s<<endl;

    int cnt = 0;
    int p = 0;
    while(s[p] != '\0') {
        if(s[p] == 'a' || s[p] == 'e' || s[p] == 'i' || s[p] == 'o' || s[p] == 'u' ) {
            cnt++;
        }
        p++;
    }
    cout<<cnt<<endl;

    // Enter the String : om gupta
    // om gupta
    // 3
    return 0;
}
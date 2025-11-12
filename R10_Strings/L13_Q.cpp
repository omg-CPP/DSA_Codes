// Input a string of length n and count all the consonants in the given string.
#include <iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    cout<<str<<endl;

    int len = str.length();
    int cnt = 0;
    for(int i = 0 ; str[i] != '\0' ; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            cnt++;
        }
    }
    cout<<"Vowels are : "<<cnt<<endl;
    cout<<"Consonants are : "<<(len-cnt)<<endl;
    // Enter string : pwians
    // pwians
    // Vowels are : 2
    // Consonants are : 4
    return 0;
}
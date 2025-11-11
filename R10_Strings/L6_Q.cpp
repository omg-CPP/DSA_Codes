#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the String : ";
    getline(cin,str);
    cout<<str<<endl;

    for(int i = 0 ; str[i] != '\0' ; i++) {
        if(i % 2 == 0) {
            str[i] = 'a';
        }
    }

    cout<<str<<endl;
    return 0;
}

// Enter the String : Om Gupta
// Om Gupta
// amaGapaa

// Enter the String : raghav
// raghav
// aaahav
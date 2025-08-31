#include <iostream>
using namespace std;
int main()
{
    // ASCII Values :

    // ->  a To z  ->  97 To 122
    // ->  A to Z  ->  65 To 90
    // ->  0 To 9  ->  48 To 57

    char ch;
    cout<<"Enter any character : ";
    cin>>ch;

    int x = (int)ch;
    if((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) {
        cout<<ch<<" is an Alphabet"<<endl;
    }
    else if((x >= 48 && x <= 57)) {
        cout<<ch<<" is a Number"<<endl;
    }
    else {
        cout<<ch<<" is a Special Character"<<endl;
    }
    return 0;
}

// Enter any character : A
// A is an Alphabet

// Enter any character : b
// b is an Alphabet

// Enter any character : 1
// 1 is a Number

// Enter any character : %
// % is a Special Character
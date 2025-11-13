#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    // lexographically : ASCII Values ke order me sort hota hai
    string str;
    cout<<"Enter the string : ";
    getline(cin,str);
    int len = str.length();
    cout<<(int)(' ')<<endl; // 32
    cout<<str<<endl;
    sort(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}

// Enter the string : dgstvsabhn
// dgstvsabhn
// abdghnsstv

// Enter the string : raghav garg is a maths teacher
// raghav garg is a maths teacher
//      aaaaaaceeggghhhimrrrssttv

// Enter the string : Name
// Name
// Naem
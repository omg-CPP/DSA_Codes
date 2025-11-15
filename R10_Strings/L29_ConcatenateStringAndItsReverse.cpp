#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<s<<endl;
    string temp = s;
    reverse(temp.begin(), temp.end());
    s = s + temp;
    cout<<s<<endl;
    return 0;
}

// Enter string : PWSkills  
// PWSkills
// PWSkillssllikSWP
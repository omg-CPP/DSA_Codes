#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
// Given a sentence ‘str’, return the word that is lexicographically maximum.
int main()
{
    string s = "decode dsa with pw";
    stringstream ss(s);
    string temp;
    // ss me se input le lo
    vector<string> v;
    while(ss >> temp) {
        v.push_back(temp);
    }

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<endl;
    }
    // decode
    // dsa
    // with
    // pw
    cout<<endl;

    sort(v.begin(), v.end());

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<endl;
    }
    // decode
    // dsa
    // pw
    // with
    cout<<endl;

    cout<<"Lexographically Maximum Word : "<<v[v.size()-1]<<endl;
    // Lexographically Maximum Word : with 
    return 0;
}
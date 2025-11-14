#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    // string str = "raghav is maths teacher. He is a DSA mentor as well!";
    string str = "My name is Om Gupta. Om Gupta is my name with Om as first name";
    stringstream ss(str);
    string temp;
    vector<string> v;
    while(ss >> temp) {
        v.push_back(temp);
    }
    // vector print
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<endl;
    }
    cout<<endl;
    sort(v.begin(),v.end());

    // vector print
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<endl;
    }

    // logic

    int maxCount = 1;
    int count = 1;
    for(int i = 1 ; i < v.size() ; i++) {
        if(v[i] == v[i-1]) {
            count++;
        }
        else {
            count = 1;
        }
        maxCount = max(maxCount,count);
    }

    for(int i = 1 ; i < v.size() ; i++) {
        if(v[i] == v[i-1]) {
            count++;
        }
        else {
            count = 1;
        }
        if(count == maxCount) {
            cout<<v[i]<<" "<<maxCount<<endl;
        }
    }
    return 0;
}

// raghav
// is
// maths
// teacher.
// He
// is
// a
// DSA
// mentor
// as
// well!

// DSA
// He
// a
// as
// is
// is
// maths
// mentor
// raghav
// teacher.
// well!

// is 2

// My
// name
// is
// Om
// Gupta.
// Om
// Gupta
// is
// my
// name
// with
// Om
// as
// first
// name

// Gupta
// Gupta.
// My
// Om
// Om
// Om
// as
// first
// is
// is
// my
// name
// name
// name
// with

// Om 3
// name 3
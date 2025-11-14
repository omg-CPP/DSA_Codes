#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string s = "raghav is    a maths teacher";
    stringstream ss(s);
    string temp;
    // ss me se input le lo
    while(ss >> temp) {
        cout<<temp<<endl;
    }
    return 0;
}

// raghav
// is
// a
// maths
// teacher
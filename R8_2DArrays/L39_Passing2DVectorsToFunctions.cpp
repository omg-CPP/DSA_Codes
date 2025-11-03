#include <iostream>
#include <vector>
using namespace std;

// Need not to mention size of 2D Vector
void change2DVector(vector<vector<int>>& v) {
    // & -> pass by reference
    // otherwise it creates a new vector
    v[0][0] = 100;
}

void length(vector<vector<int>>& v) {
    cout<<v.size()<<endl;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);

    vector<int> v3;
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);

    vector<vector<int>> vec; // 2D Vector
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);

    cout<<vec[0][0]<<endl; // 1
    change2DVector(vec);
    cout<<vec[0][0]<<endl; // 100

    length(vec); // 3

    return 0;
}
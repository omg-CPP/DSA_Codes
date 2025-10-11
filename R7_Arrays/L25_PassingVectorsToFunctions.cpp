#include <iostream>
#include <vector>
using namespace std;
// Vectors are passed by value
// Each time you pass, a new vector is created
void change(vector<int> a) {
    // a is a vector
    a[0] = 10;
    for(int i = 0 ; i < a.size() ; i++) {
        cout<<a[i]<<" ";
    }
    // 10 10 6 1 
    cout<<endl;
}
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 9 10 6 1 
    cout<<endl;

    change(v);

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 9 10 6 1 
    cout<<endl;

    return 0;
}
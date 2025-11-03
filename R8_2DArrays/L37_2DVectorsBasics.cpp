#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // int arr[3][4];
    // vector<int> v;
    // vector<vector<int>> vec;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    for(int i = 0 ; i < v1.size() ; i++) {
        cout<<v1[i]<<" ";
    }
    // 1 2 3 
    cout<<endl;

    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);

    for(int i = 0 ; i < v2.size() ; i++) {
        cout<<v2[i]<<" ";
    }
    // 4 5 

    cout<<endl;

    vector<int> v3;
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);

    for(int i = 0 ; i < v3.size() ; i++) {
        cout<<v3[i]<<" ";
    }
    // 6 7 8 9 10 

    cout<<endl;

    vector<vector<int>> vec; // 2D Vector
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);

    cout<<vec[0][1]<<endl; // 2

    for(int i = 0 ; i < vec.size() ; i++) {
        for(int j = 0 ; j < vec[i].size() ; j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    // 1 2 3 
    // 4 5 
    // 6 7 8 9 10 

    cout<<endl;

    cout<<vec.size()<<endl; // 3
    cout<<vec[0].size()<<endl; // 3
    cout<<vec[1].size()<<endl; // 2
    cout<<vec[2].size()<<endl; // 5

    cout<<endl;

    vector<int> v(5);
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 0 0 0 0 0 
    cout<<endl;

    vector<int> vr(5,4);
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<vr[i]<<" ";
    }
    // 4 4 4 4 4 
    cout<<endl;

    vector<int> arr(3);
    arr.push_back(1);
    for(int i = 0 ; i < arr.size() ; i++) {
        cout<<arr[i]<<" ";
    }
    // 0 0 0 1 
    cout<<endl;
    return 0;
}
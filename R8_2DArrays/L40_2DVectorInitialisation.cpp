#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(5,2);
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 2 2 2 2 2 
    cout<<endl;

    vector<vector<int>> vec(3,vector<int>(4));
    // 3 rows and 4 columns
    for(int i = 0 ; i < vec.size() ; i++) {
        for(int j = 0 ; j < vec[i].size() ; j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    // 0 0 0 0 
    // 0 0 0 0 
    // 0 0 0 0 
    cout<<endl;

    vector<vector<int>> vr(3,vector<int>(4,2));
    // 3 rows and 4 columns with all elements = 2
    for(int i = 0 ; i < vr.size() ; i++) {
        for(int j = 0 ; j < vr[i].size() ; j++) {
            cout<<vr[i][j]<<" ";
        }
        cout<<endl;
    }
    // 2 2 2 2 
    // 2 2 2 2 
    // 2 2 2 2 
    cout<<endl;

    cout<<vr.size()<<endl; // 3 : No of rows
    cout<<vr[0].size()<<endl; // 4 : No of columns


    cout<<endl;

    vector<vector<int>> arr = {{1,2,3},{4,5}};
    for(int i = 0 ; i < arr.size() ; i++) {
        for(int j = 0 ; j < arr[i].size() ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 4 5 
    cout<<endl;

    arr.push_back({6,7,8,9,10});

    for(int i = 0 ; i < arr.size() ; i++) {
        for(int j = 0 ; j < arr[i].size() ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 4 5 
    // 6 7 8 9 10 
    cout<<endl;

    arr.pop_back();

    for(int i = 0 ; i < arr.size() ; i++) {
        for(int j = 0 ; j < arr[i].size() ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 4 5 
    cout<<endl;
    return 0;
}
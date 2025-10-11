#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(5);

    cout<<"Enter elements of vector : ";
    for(int i = 0 ; i < v.size() ; i++) {
        cin>>v[i];
    }

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }

    // Enter elements of vector : 4 5 6 7 8
    // 4 5 6 7 8 


    vector<int> vec;
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;
    cout<<"Enter elements of vector : ";
    for(int i = 0 ; i < n ; i++) {
        int x;
        cin>>x;
        vec.push_back(x);
    }

    for(int i = 0 ; i < vec.size() ; i++) {
        cout<<vec[i]<<" ";
    }

    // Enter no of elements : 5
    // Enter elements of vector : 1 2 3 4 5
    // 1 2 3 4 5 

    return 0;
}
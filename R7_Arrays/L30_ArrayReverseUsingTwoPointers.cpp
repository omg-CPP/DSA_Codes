#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& a) {
    for(int i = 0 ; i < a.size() ; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v;
    cout<<v.size()<<endl; // 0
    int n;
    cout<<"Enter array size : ";
    cin>>n;

    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<v.size()<<endl; // 8
    cout<<v.capacity()<<endl; // 8

    displayVector(v);
    // 1 3 2 4 3 4 1 6 

    // without using extra array

    // using while loop

    int i = 0;
    int j = v.size()-1;
    while(i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }

    // Using for loop for two variables

    // for(int i = 0, j = v.size()-1 ; i <= j ; i++, j--) {
    //     int temp = v[i];
    //     v[i] = v[j];
    //     v[j] = temp;
    // }
    
    // 0
    // Enter array size : 8
    // Enter elements : 1 3 2 4 3 4 1 6 
    // 8
    // 8
    // 1 3 2 4 3 4 1 6 
    // 6 1 4 3 4 2 3 1 

    displayVector(v);
    // 6 1 4 3 4 2 3 1 
    return 0;
}

// 0
// Enter array size : 8
// Enter elements : 1 3 2 4 3 4 1 6 
// 8
// 8
// 1 3 2 4 3 4 1 6 
// 6 1 4 3 4 2 3 1 
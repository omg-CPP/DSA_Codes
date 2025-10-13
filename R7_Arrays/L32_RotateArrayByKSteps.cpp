#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& a) {
    for(int i = 0 ; i < a.size() ; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

void reversePart(vector<int>& v, int i, int j) {
    while(i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    return;
}

int main()
{
    // Right Rotation
    
    int k;
    cout<<"Enter k : ";
    cin>>k;
    
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);
    v.push_back(4);
    v.push_back(8);

    int n = v.size();

    k = k % n; // to remove cpmplete rotations and to get 1 <= k <= n-1

    displayVector(v);

    reversePart(v,0,n-k-1);
    reversePart(v,n-k,n-1);
    reversePart(v,0,n-1);

    displayVector(v);

    return 0;
}

// Enter k : 2
// 1 6 2 3 7 4 8 
// 4 8 1 6 2 3 7 

// Enter k : 18
// 1 6 2 3 7 4 8 
// 3 7 4 8 1 6 2 

// Enter k : 9
// 1 6 2 3 7 4 8 
// 4 8 1 6 2 3 7 
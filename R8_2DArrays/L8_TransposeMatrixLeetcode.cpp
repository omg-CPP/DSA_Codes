#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size(); // rows
    int n = matrix[0].size(); // columns
    vector<vector<int>> tr(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            tr[i][j] = matrix[j][i];
        }
    }
    return tr;
}

int main()
{
    vector<vector<int>> matrix = {{2,4,-1},{-10,5,11},{18,-7,6}};
    cout<<"Original Matrix : "<<endl;
    for(int i = 0 ; i < matrix.size() ; i++) {
        for(int j = 0 ; j < matrix[i].size() ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    vector<vector<int>> tr = transpose(matrix);
    cout<<"Transpose Matrix : "<<endl;
    for(int i = 0 ; i < tr.size() ; i++) {
        for(int j = 0 ; j < tr[i].size() ; j++) {
            cout<<tr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Original Matrix : 
// 2 4 -1 
// -10 5 11 
// 18 -7 6 

// Transpose Matrix : 
// 2 -10 18 
// 4 5 -7 
// -1 11 6 
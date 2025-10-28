#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // transpose
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i < j) { // To swap only once
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    // reverse each row
    for(int k = 0 ; k < n ; k++) {
        int i = 0;
        int j = n-1;
        while(i <= j) {
            // swapping k,i and k,j
            int temp = matrix[k][i];
            matrix[k][i] = matrix[k][j];
            matrix[k][j] = temp;
            i++;
            j--;
        }
    }
    return;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Original Matrix : "<<endl;
    for(int i = 0 ; i < matrix.size() ; i++) {
        for(int j = 0 ; j < matrix[i].size() ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    rotate(matrix);
    cout<<"Matrix Rotated by 90 Degrees Clockwise : "<<endl;
    for(int i = 0 ; i < matrix.size() ; i++) {
        for(int j = 0 ; j < matrix[i].size() ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}


// Original Matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 

// Matrix Rotated by 90 Degrees Clockwise : 
// 7 4 1 
// 8 5 2 
// 9 6 3 

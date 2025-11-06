#include <iostream>
#include <vector>
using namespace std;

vector<int> FindExitPoint(int m, int n, vector<vector<int>>& matrix) {
    int i = 0;
    int j = 0;
    int face = 0;
    while(true) {
        if(matrix[i][j] == 1) {
            matrix[i][j] = 0;
            if(face == 0) { // east
                i++;
                face = 1; // south
            }
            else if(face == 1) { // south
                j--;
                face = 2; // west
            }
            else if(face == 2) { // west
                i--;
                face = 3; // north
            }
            else if(face == 3) { // north
                j++;
                face = 0; // east
            }
        }
        else { // matrix[i][j] == 0
            if(face == 0) { // east
                j++;
            }
            else if(face == 1) { // south
                i++;
            }
            else if(face == 2) { // west
                j--;
            }
            else if(face == 3) { // north
                i--;
            }
        }

        if(i < 0) {
            i++;
            break;
        }
        else if(i == m) {
            i--;
            break;
        }
        else if(j < 0) {
            j++;
            break;
        }
        else if(j == n) {
            j--;
            break;
        }
    }
    return {i,j};
}
int main()
{
    vector<vector<int>> matrix = {{0,1,0},{0,1,1},{0,0,0}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> exit = FindExitPoint(m,n,matrix);
    for(int i = 0 ; i < exit.size() ; i++) {
        cout<<exit[i]<<" ";
    }
    // 1 0 
    return 0;
}
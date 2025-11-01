#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;

    
    int min_row = 0;
    int min_col = 0;
    int max_row = n-1;
    int max_col = n-1;
    int a = 1;
    int tne = n*n;
    int count = 0;
    int ans[n][n];

    while((min_row <= max_row) && (min_col <= max_col)) {

        // right
        // left to right
        // minr -> const
        // minc -> maxc
        for(int j = min_col ; j <= max_col ; j++) {
            ans[min_row][j] = a++; 
        }
        min_row++;
        if(min_row > max_row || min_col > max_col) {
            break;
        }

        // down
        // top to bottom
        // maxc -> const
        // minr -> maxr
        for(int i = min_row ; i <= max_row ; i++) {
            ans[i][max_col] = a++;
        }
        max_col--;
        if(min_row > max_row || min_col > max_col) {
            break;
        }

        // left
        // right to left
        // maxr -> const
        // maxc -> minc
        for(int j = max_col ; j >= min_col ; j--) {
            ans[max_row][j] = a++;
        }
        max_row--;
        if(min_row > max_row || min_col > max_col) {
            break;
        }

        // top
        // bottom to top
        // minc -> const
        // maxr -> minr
        for(int i = max_row ; i >= min_row ; i--) {
            ans[i][min_col] = a++;
        }
        min_col++;
        if(min_row > max_row || min_col > max_col) {
            break;
        }
    }

    cout<<"Required Matrix : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 3
// Required Matrix : 
// 1 2 3 
// 8 9 4 
// 7 6 5 

// Enter n : 1
// Required Matrix : 
// 1 

// Enter n : 4
// Required Matrix : 
// 1 2 3 4 
// 12 13 14 5 
// 11 16 15 6 
// 10 9 8 7 

// Enter n : 2
// Required Matrix : 
// 1 2 
// 4 3 

// Enter n : 5
// Required Matrix : 
// 1 2 3 4 5 
// 16 17 18 19 6 
// 15 24 25 20 7 
// 14 23 22 21 8 
// 13 12 11 10 9 
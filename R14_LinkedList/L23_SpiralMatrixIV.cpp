// Leetcode 2326

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public :
    int value;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->next = NULL;
    }
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> ans(m,vector<int>(n,-1));
    int min_row = 0;
    int min_col = 0;
    int max_row = m-1;
    int max_col = n-1;
    int a = 1;
    int tne = m*n;
    ListNode* temp = head;
    while((min_row <= max_row) && (min_col <= max_col)) {

        // right
        // left to right
        // minr -> const
        // minc -> maxc
        for(int j = min_col ; j <= max_col && a <= tne ; j++) {
            if(temp == NULL) {
                return ans;
            }
            ans[min_row][j] = temp->value;
            temp = temp->next;
        }
        min_row++;
        // if(min_row > max_row || min_col > max_col) {
        //     break;
        // }

        // down
        // top to bottom
        // maxc -> const
        // minr -> maxr
        for(int i = min_row ; i <= max_row && a <= tne ; i++) {
            if(temp == NULL) {
                return ans;
            }
            ans[i][max_col] = temp->value;
            temp = temp->next;
        }
        max_col--;
        // if(min_row > max_row || min_col > max_col) {
        //     break;
        // }

        // left
        // right to left
        // maxr -> const
        // maxc -> minc
        for(int j = max_col ; j >= min_col && a <= tne ; j--) {
            if(temp == NULL) {
                return ans;
            }
            ans[max_row][j] = temp->value;
            temp = temp->next;
        }
        max_row--;
        // if(min_row > max_row || min_col > max_col) {
        //     break;
        // }

        // top
        // bottom to top
        // minc -> const
        // maxr -> minr
        for(int i = max_row ; i >= min_row && a <= tne ; i--) {
            if(temp == NULL) {
                return ans;
            }
            ans[i][min_col] = temp->value;
            temp = temp->next;
        }
        min_col++;
        // if(min_row > max_row || min_col > max_col) {
        //     break;
        // }
    }
    return ans;
}

int main()
{
    return 0;
}
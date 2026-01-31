// Ceil In BST :: GFG

// Ceil :: val >= x
// Smallest Number greater than x

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode {
public : 
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// 1  ≤ Value of nodes ≤ 10^5
// T.C. = O(log2(N))
// S.C. = O(1)
int findCeil(TreeNode* root, int x) {
    TreeNode* curr = root;
    int ans = -1;
    while(curr != NULL) {
        if(curr->val == x) {
            ans = curr->val;
            return ans;
        }
        if(curr->val > x) {
            ans = curr->val;
            curr = curr->left;
        }
        else { // curr->val < x
            curr = curr->right;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
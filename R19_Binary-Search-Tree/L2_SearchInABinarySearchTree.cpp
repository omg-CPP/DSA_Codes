// Leetcode : 700

#include <iostream>
#include <vector>
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

// At worst case we are moving either left or right and moving to the leaf node so time will be logN which is the height of the tree.
// T.C. = O(H) = O(log2(N))
// S.C. = O(1)
TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* curr = root;
    while(curr != NULL && curr->val != val) {
        curr = val < curr->val ? curr->left : curr->right;
    }
    return curr;
}


TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->val == val) {
            return curr;
        }
        else if(curr->val < val) {
            curr = curr->right;
        }
        else { // curr->val > val
            curr = curr->left;
        }
    }
    return curr;
}

int main()
{
    return 0;
}
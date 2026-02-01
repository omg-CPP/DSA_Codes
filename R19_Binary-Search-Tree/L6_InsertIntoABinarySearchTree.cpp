// Leetcode : 701

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

// It is guaranteed that the new value does not exist in the original BST.
// Assuming, Tree is Height Balanced BST
// T.C. = O(log2(N))
// S.C. = O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) {
        return new TreeNode(val);
    }
    TreeNode* curr = root;
    while(true) {
        if(curr->val <= val) {
            if(curr->right != NULL) {
                curr = curr->right;
            }
            else { // curr->right == NULL
                curr->right = new TreeNode(val);
                break;
            }
        }
        else { // curr->val > val
            if(curr->left != NULL) {
                curr = curr->left;
            }
            else { // curr->left == NULL
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}


int main()
{
    return 0;
}
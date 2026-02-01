// Leetcode : 450

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

TreeNode* findLastRight(TreeNode* root) {
    if(root->right == NULL) {
        return root;
    }
    return findLastRight(root->right);
}


TreeNode* helper(TreeNode* root) {
    if(root->left == NULL) {
        return root->right;
    }
    else if(root->right == NULL) {
        return root->left;
    }
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

// T.C. = O(H)
// S.C. = O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->val == key) {
        return helper(root);
    }

    TreeNode* dummy = root;
    while(dummy != NULL) {
        if(dummy->val > key) {
            if(dummy->left != NULL && dummy->left->val == key) {
                dummy->left = helper(dummy->left);
                break;
            }
            else {
                dummy = dummy->left;
            }
        }
        else {
            if(dummy->right != NULL && dummy->right->val == key) {
                dummy->right = helper(dummy->right);
                break;
            }
            else {
                dummy = dummy->right;
            }
        }
    }
    return root;
}


int main()
{
    return 0;
}
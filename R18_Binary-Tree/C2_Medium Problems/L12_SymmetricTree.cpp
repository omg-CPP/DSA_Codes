// Leetcode : 101

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

// T.C. = O(n)
// S.C. = O(n) :: worst case :: Skewed Binary Tree
bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
    if(left == NULL || right == NULL) {
        // returns true only if both are null
        return left == right;
    }
    if(left->val != right->val) {
        return false;
    }
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right,right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) {
        return true;
    }
    return isSymmetricHelp(root->left, root->right);
}

int main()
{
    return 0;
}
// Leetcode : 110

// Balanced Binary Trees : for every node, height(left) - height(right) <= 1

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
// S.C. = O(height) in best case
// S.C. = O(n) in worst case :: skewed binary tree
int dfsHeight(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftDepth = dfsHeight(root->left);
    if(leftDepth == -1) {
        return -1;
    }
    int rightDepth = dfsHeight(root->right);
    if(rightDepth == -1) {
        return -1;
    }
    if(abs(leftDepth-rightDepth) > 1) {
        return -1;
    }
    return 1 + max(leftDepth,rightDepth);
}

bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;
}

int main()
{
    return 0;
}
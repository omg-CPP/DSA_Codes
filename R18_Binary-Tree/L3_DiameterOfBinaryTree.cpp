// Leetcode : 543
// Diameter : Longest Path betweem two nodes
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

int levels(TreeNode* root, int& diameter) {
    if(root == NULL) {
        return 0;
    }
    int leftLevels = levels(root->left,diameter);
    int rightLevels = levels(root->right,diameter);
    diameter = max(diameter, leftLevels + rightLevels);
    return 1 + max(leftLevels,rightLevels);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    levels(root,diameter);
    return diameter;
}

int main()
{
    return 0;
}
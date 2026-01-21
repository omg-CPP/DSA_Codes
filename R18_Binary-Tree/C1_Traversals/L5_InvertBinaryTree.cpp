// Leetcode : 226
#include <bits/stdc++.h>
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

void helper(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    helper(root->left);
    helper(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    helper(root);
    return root;
}

int main()
{
    return 0;
}
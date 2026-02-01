// Leetcode : 98

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

// test case when root = [2147483647]
// so we take long min and long max
bool validateBST(TreeNode* root, long minVal, long maxVal) {
    if(root == NULL) {
        return true;
    }
    if(root->val >= maxVal || root->val <= minVal) { 
        return false;
    }
    return validateBST(root->left,minVal,root->val) && validateBST(root->right,root->val,maxVal);
}

// T.C. = O(N)
// S.C. = O(1)
bool isValidBST(TreeNode* root) {
    return validateBST(root,LONG_MIN,LONG_MAX);
}

int main()
{
    return 0;
}
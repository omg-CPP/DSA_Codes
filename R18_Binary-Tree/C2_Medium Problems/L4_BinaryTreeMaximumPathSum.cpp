// Leetcode : 124

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

int dfsPathSum(TreeNode* root, int& maxSum) {
    if(root == NULL) {
        return 0;
    }
    // to neglect -ve cases
    int leftSum = max(0,dfsPathSum(root->left,maxSum));
    int rightSum = max(0,dfsPathSum(root->right,maxSum));
    maxSum = max(maxSum,root->val+leftSum+rightSum);
    return (root->val) + max(leftSum,rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    dfsPathSum(root,maxSum);
    return maxSum;
}

int main()
{
    return 0;
}
// Leetcode : 236 :: LCA

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
// S.C. = O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // base case
    if(root == NULL || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    // result 
    // case is included already
    // if(left == NULL && right == NULL) {
    //     return NULL;
    // }
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { // left != NULL and right != NULL
        return root;
    }
}

int main()
{
    return 0;
}
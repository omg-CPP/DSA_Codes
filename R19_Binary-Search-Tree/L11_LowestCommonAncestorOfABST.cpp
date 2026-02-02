// Leetcode : 235

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

// T.C. = O(H) = O(log2(N))
// S.C. = O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) {
        return NULL;
    }
    int currVal = root->val;
    if(currVal > p->val && currVal > q->val) {
        return lowestCommonAncestor(root->left,p,q);
    }
    if(currVal < p->val && currVal < q->val) {
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;
}


    
int main()
{
    return 0;
}
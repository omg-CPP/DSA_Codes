// Root To Leaf Paths :: GFG

// Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

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

// Recursion + Backtracking
// T.C. = O(N)
// Where N is the number of nodes in the tree
// We visit each node exactly once
// At each node, we perform O(1) operations (push, pop, check conditions)

// S.C. = O(H)
// O(H) for recursion stack space, where H is the height of the tree
// Worst case (skewed tree): O(N)
// Best case (balanced tree): O(log N)
void helper(TreeNode* root, vector<int>& v, vector<vector<int>>& ans) {
    if(root == NULL) {
        return;
    }
    v.push_back(root->val);
    // condition for leaf nodes
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(v);
        v.pop_back();
        return;
    }
    helper(root->left,v,ans);
    helper(root->right,v,ans);
    // pop after both children are processed
    v.pop_back();
}

vector<vector<int>> Paths(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    vector<int> v;
    helper(root,v,ans);
    return ans;
}


int main()
{
    return 0;
}

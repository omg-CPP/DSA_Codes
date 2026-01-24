// Leetcode : 104
// Maximum Depth of the Binary Tree

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

void displayTree(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

// T.C. = O(n) :: traversing each node once
// S.C. = O(Height) :: Best Case
// S.C. = O(n) :: Worst Case :: Skewed Binary Tree

int maxDepth(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth,rightDepth);
}


int main()
{
    TreeNode* a = new TreeNode(1); // root node -> a
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    // Connections
    a->left = b; a->right = c;
    b->left = d; b->right = e;  
    c->left = f; c->right = g;

    // Tree = Recursion
    displayTree(a);
    // 1 2 4 5 3 6 7 
    cout<<endl;
    cout<<maxDepth(a)<<endl; // 3
    return 0;
}


//           1
//        2     3
//      4  5   6  7

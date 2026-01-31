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


// BST : L < N < R

// All the nodes in the left sub tree should be smaller than the root node and all the nodes in the right sub tree should be greater than the root node, and this is true for the left sub tree and the right sub tree as well.

int main()
{
    return 0;
}
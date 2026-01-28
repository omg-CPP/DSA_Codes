// Leetcode : 222
// Design an algorithm that runs in less than O(n) time complexity.
#include <iostream>
#include <vector>
#include <cmath>
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

// Brute Force :: Any DFS Traversal with .
// T.C = O(N) 
// S.C. = O(H) = O(logN) in complete binary tree
void preOrder(TreeNode* root, int& nodes) {
    if(root == NULL) {
        return;
    }
    nodes++;
    preOrder(root->left,nodes);
    preOrder(root->right,nodes);
}
int countNodesNaive(TreeNode* root) {
    int nodes = 0;
    preOrder(root,nodes);
    return nodes;
}


int findLeftHeight(TreeNode* node) {
    int ht = 0;
    while(node != NULL) {
        ht++;
        node = node->left;
    }
    return ht;
}

int findRightHeight(TreeNode* node) {
    int ht = 0;
    while(node != NULL) {
        ht++;
        node = node->right;
    }
    return ht;
}

// Optimal : Using Property of Complete Binary Tree
// No of nodes in a complete binary tree is 2^h - 1
// T.C. = O(logn)*O(logn)
//           fun * ht
// S.C. = O(logn)
int countNodes(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh) {
        return pow(2,lh)-1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main()
{
    return 0;
}
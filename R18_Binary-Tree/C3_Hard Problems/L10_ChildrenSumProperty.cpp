// Children Sum Property
// Convert tree into a tree that follows the children sum property

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

// T.C. = O(N)
// S.C. = O(H)
void changeTree(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    int child = 0;
    if(root->left != NULL) {
        child += (root->left)->val;
    }
    if(root->right != NULL) {
        child += (root->right)->val;
    }

    if(child >= root->val) {
        root->val = child;
    }
    else {
        if(root->left != NULL) {
            (root->left)->val = root->val;
        }
        if(root->right != NULL) {
            (root->right)->val = root->val;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left != NULL) {
        total += (root->left)->val;
    }
    if(root->right!= NULL) {
        total += (root->right)->val;
    }
    // checking that it should not be a leaf node
    if(root->left != NULL || root->right != NULL) {
        root->val = total;
    }
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
    a->left = b; 
    a->right = c;
    b->left = d;    c->left = f;
    b->right = e;   c->right = g;

    // Tree = Recursion
    displayTree(a);
    // 1 2 4 5 3 6 7 

    cout<<endl;

    changeTree(a);

    displayTree(a);
    // 22 9 4 5 13 6 7 
    return 0;
}

// Doesn't follows Children Sum Property
//      1
//    2   3
//   4 5 6 7

// Children Sum Property
//      22
//    9   13
//   4 5 6  7
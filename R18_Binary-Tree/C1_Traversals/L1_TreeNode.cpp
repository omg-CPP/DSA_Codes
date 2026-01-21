// Trees are Hierarchial Data Structures
// Binary Trees
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
    return 0;
}

//        a
//      b   c 
//     d e f g
// Leetcode : 100

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

// PreOrder Traversal : Root Left Right
// T.C. = O(n)
// S.C. = O(n)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL) {
        return (p == q);
    }
    return (p->val == q-> val) && isSameTree(p->left,q->left) 
    && isSameTree(p->right,q->right);
}


int main()
{
    return 0;
}
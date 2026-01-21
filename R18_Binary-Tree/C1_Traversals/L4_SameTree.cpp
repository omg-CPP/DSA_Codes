// Leetcode : 100
#include <bits/stdc++.h>
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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return false;
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    if(p->val != q->val) {
        return false;
    }
    bool lstAns = isSameTree(p->left,q->left);
    if(lstAns == false) {
        return false;
    }
    bool rstAns = isSameTree(p->right,q->right);
    if(rstAns == false) {
        return false;
    }
    return true;
}

int main()
{
    return 0;
}
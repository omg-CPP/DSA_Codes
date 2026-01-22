// Leetcode : 94

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

void inOrder(TreeNode* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}

// In Order Traversal : Left Root Right
// T.C. = O(n) :: traversing each tree node once
// S.C. = O(n) :: Auxillary Stack Space of Recursion
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inOrder(root,ans);
    return ans;
}

int main()
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    TreeNode* h = new TreeNode(8);
    TreeNode* i = new TreeNode(9);
    TreeNode* j = new TreeNode(10);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = g; c->right = h;
    e->left = f;
    h->left = i; h->right = j;

    displayTree(a);
    // 1 2 4 5 6 3 7 8 9 10 
    cout<<endl;

    vector<int> ans = inorderTraversal(a);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 4 2 6 5 1 7 3 9 8 10 
    cout<<endl;
    return 0;
}

//        1
//     2     3
//   4   5  7  8
//      6     9 10

// in order : Left Root Right
// 4 2 6 5 1 7 3 9 8 10
// Leetcode : 144

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

void preOrder(TreeNode* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }
    ans.push_back(root->val);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}

// Pre Order Traversal : Root Left Right
// T.C. = O(n) :: traversing each tree node once
// where n is the number of nodes
// height of BT = levels - 1
// null is also considered in height
// S.C. = O(levels+1) :: O(height+2) :: O(h) :: O(n)
// S.C. = O(n) in worst case in skewed binary trees case
// S.C. = O(h) = O(logn) in balanced binary trees
// maximum height of call stack at a time
vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> ans;
    preOrder(root,ans);
    return ans;
}

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

    vector<int> ans = preOrderTraversal(a);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 2 4 5 6 3 7 8 9 10
    cout<<endl;
    return 0;
}

//        1
//     2     3
//   4   5  7  8
//      6     9 10

// pre order : Root Left Right
// 1 2 4 5 6 3 7 8 9 10
// Leetcode : 145

#include <iostream>
#include <vector>
#include <stack>
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


// Iterative Traversal using 2 Stacks
// Post Order Traversal : Left Right Root
// T.C. = O(n) :: traversing each tree node once
// S.C. = O(2n)
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postOrder;
    if(root == NULL) {
        return postOrder;
    }
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty()) {
        TreeNode* node = root;
        st1.pop();
        st2.push(node);
        if(node->left != NULL) {
            st1.push(node->left);
        }
        if(node->right != NULL) {
            st1.push(node->right);
        }
    }
    
    while(!st2.empty()) {
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }
    return postOrder;
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

    vector<int> ans = postorderTraversal(a);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 4 6 5 2 7 9 10 8 3 1
    cout<<endl;
    return 0;
}

//        1
//     2     3
//   4   5  7  8
//      6     9 10

// post order : Left Right Root
// 4 6 5 2 7 9 10 8 3 1
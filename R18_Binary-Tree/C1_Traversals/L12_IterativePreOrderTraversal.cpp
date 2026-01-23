// Leetcode : 144
// Pre Order Traversal :: Root Left Right
// Stack Data Structure


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

// T.C. = O(n)
// S.C. = O(n) :: stack used
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preOrder;
    if(root == NULL) {
        return preOrder; // empty preOrder
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        preOrder.push_back(node->val);
        if(node->right != NULL) {
            st.push(node->right);
        }
        if(node->left != NULL) {
            st.push(node->left);
        }
    }
    return preOrder;
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

    vector<int> ans = preorderTraversal(a);
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



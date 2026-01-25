// Tree Boundary Traversal :: GFG

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

bool isLeaf(TreeNode* root) {
    if(root->left == NULL && root->right == NULL) {
        return true;
    }
    return false;
}

// T.C. = O(H)
void addLeftBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* curr = root->left;
    while(curr != NULL) {
        if(!isLeaf(curr)) {
            ans.push_back(curr->val);
        }
        if(curr->left != NULL) {
            curr = curr->left;
        }
        else { // curr->left == NULL
            curr = curr->right;
        }
    }
}

// T.C. = O(n)
void addLeaves(TreeNode* root, vector<int>& ans) {
    if(isLeaf(root)) {
        ans.push_back(root->val);
    }
    if(root->left != NULL) {
        addLeaves(root->left,ans);
    }
    if(root->right != NULL) {
        addLeaves(root->right,ans);
    }
}

// T.C. = O(H)
void addRightBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* curr = root->right;
    vector<int> temp;
    while(curr != NULL) {
        if(!isLeaf(curr)) {
            temp.push_back(curr->val);
        }
        if(curr->right != NULL) {
            curr = curr->right;
        }
        else { // curr->right == NULL
            curr = curr->left;
        }
    }
    for(int i = temp.size()-1 ; i >= 0 ; i--) {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    if(!isLeaf(root)) { // check for root is not a leaf node
        ans.push_back(root->val);
    }
    else {
        ans.push_back(root->val);
        return ans;
    }
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}

int main()
{
    return 0;
}
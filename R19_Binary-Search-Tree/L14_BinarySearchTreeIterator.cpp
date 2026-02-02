// Leetcode : 173

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

// Brute Force
// T.C. = O(1)
// S.C. = O(N)
class BSTIterator {
private:
    vector<int> dfs;  // Move to class data members
    int idx;          // Move to class data members

public:
    void helperDFS(TreeNode* root, vector<int>& dfs) {
        if(root == NULL) {
            return;
        }
        helperDFS(root->left,dfs);
        dfs.push_back(root->val);
        helperDFS(root->right,dfs);
    }

    BSTIterator(TreeNode* root) {
        idx = 0; // Initialize index
        helperDFS(root,dfs); // Populate the dfs vector
    }
    
    int next() {
        return dfs[idx++];
    }
    
    bool hasNext() {
        if(idx < dfs.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};

// ********************************************************

// Optimal Force
// T.C. = O(1)
// S.C. = O(H) = O(logN)
class BSTIterator {
private: 
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while(node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};


int main()
{
    return 0;
}
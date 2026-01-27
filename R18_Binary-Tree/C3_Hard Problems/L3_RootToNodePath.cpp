// Root To Node Path

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

// In Order Traversal
// T.C. = O(n)
// S.C. = O(H)
bool getPath(TreeNode* root, vector<int>& ans, int x) {
    if(root == NULL) {
        return false;
    }
    ans.push_back(root->val);
    if(root->val == x) {
        return true;
    }
    if(getPath(root->left,ans,x) || getPath(root->right,ans,x)) {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A == NULL) {
        return ans;
    }
    getPath(A,ans,B);
    return ans;
}

int main()
{
    return 0;
}

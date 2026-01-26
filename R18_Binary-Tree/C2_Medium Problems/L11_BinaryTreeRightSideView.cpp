// Leetcode : 199

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

void dfsRightSideView(TreeNode* root, int level, vector<int>& ans) {
    if(root == NULL) {
        return;
    }
    if(ans.size() == level) {
        ans.push_back(root->val);
    }
    dfsRightSideView(root->right,level+1,ans);
    dfsRightSideView(root->left,level+1,ans);
}

// last node of every level is right view
// reverse pre order traversal Right Left Root
// T.C. = O(n)
// S.C. = O(H)
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    dfsRightSideView(root,0,ans);
    return ans;
}

int main()
{
    return 0;
}
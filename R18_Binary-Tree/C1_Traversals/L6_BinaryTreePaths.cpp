// Leetcode : 257
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

void helper(TreeNode* root, string s, vector<string>& ans) {
    if(root == NULL) {
        return;
    }
    string a = to_string(root->val);
    // checking for leaf nodes
    if(root->left == NULL && root->right == NULL) {
        s += a;
        ans.push_back(s);
        return;
    }
    helper(root->left,s+a+"->",ans);
    helper(root->right,s+a+"->",ans);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    helper(root,"",ans);
    return ans;
}

int main()
{
    return 0;
}
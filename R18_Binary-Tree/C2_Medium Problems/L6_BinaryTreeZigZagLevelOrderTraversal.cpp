// Leetcode : 103

#include <iostream>
#include <vector>
#include <queue>
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

// T.C. = O(n)
// S.C. = O(n) :: queue
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true; // Dirn : Left -> Right
    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        for(int i = 0 ; i < size ; i++) {
            TreeNode* node = q.front();
            q.pop();

            // find position to fill my node's value
            int idx = (leftToRight) ? i : (size-1-i);

            row[idx] = node->val;

            if(node->left != NULL) {
                q.push(node->left);
            }
            if(node->right != NULL) {
                q.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    return 0;
}
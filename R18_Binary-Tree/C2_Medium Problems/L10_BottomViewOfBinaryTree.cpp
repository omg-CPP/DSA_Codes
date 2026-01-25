// Bottom View Of Binary Tree :: GFG

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
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

// Level Order Traversal
// T.C. = O(n)
// S.C. = O(n+n) = O(n)
//       queue+map
vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    // line,node->val
    map<int,int> mp; 
    // map always stores in sorted order
    //          TreeNode,line
    queue<pair<TreeNode*, int>> q;
    q.push({root,0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        
        // everytime value is overridden
        mp[line] = node->val;

        if(node->left != NULL) {
            q.push({node->left,line-1});
        }
        if(node->right != NULL) {
            q.push({node->right,line+1});
        }
    }

    for(auto it : mp) {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    return 0;
}
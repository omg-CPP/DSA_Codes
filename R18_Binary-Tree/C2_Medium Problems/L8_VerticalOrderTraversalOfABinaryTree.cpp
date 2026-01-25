// Leetcode : 987

#include <iostream>
#include <vector>
#include <map>
#include <set>     // multiset
#include <queue>
#include <utility> // pair
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

// T.C. = O(n*logn) -> multiset
// S.C. = O(n) + O(n)
// Dry Run is pending
// Level Order Traversal
vector<vector<int>> verticalTraversal(TreeNode* root) {
//  verticals levels  multinodes
    map<int, map<int, multiset<int>>> nodes;
//            Nodes       verticals,levels
    queue<pair<TreeNode*, pair<int,int>>> todo;

    todo.push({root,{0,0}});

    while(!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;  // vertical
        int y = p.second.second; // level
        nodes[x][y].insert(node->val);
        if(node->left != NULL) {
            todo.push({node->left, {x-1, y+1}});
        }
        if(node->right != NULL) {
            todo.push({node->right, {x+1, y+1}});
        }
    }

    vector<vector<int>> ans;
    // map<int, map<int, multiset<int>>> nodes;
    for(auto p : nodes) {
        vector<int> col;
        // map<int, multiset<int>>>
        for(auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{
    return 0;
}
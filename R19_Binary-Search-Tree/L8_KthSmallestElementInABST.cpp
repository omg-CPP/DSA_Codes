// Leetcode : 230

#include <iostream>
#include <vector>
#include <algorithm>
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

// pre order traversal :: O(N)
void helperDFS(TreeNode* root, vector<int>& dfs) {
    if(root == NULL) {
        return;
    }
    dfs.push_back(root->val);
    helperDFS(root->left,dfs);
    helperDFS(root->right,dfs);
}

// T.C. = O(N) + O(NlogN)
// S.C. = O(N)
int kthSmallestNaive(TreeNode* root, int k) {
    vector<int> dfs;
    helperDFS(root,dfs);
    sort(dfs.begin(), dfs.end());
    return dfs[k-1];
    // return dfs[dfs.size()-k];
}

// ************************************************

// T.C. = O(N)
// S.C. = O(H)
// inorder traversal
// We are traversing inorder which is in ascending order so we get when count == k for the kth smallest
void helperKthSmallest(TreeNode* root, int& count, int k, int& kthSmallest) {
    if(root == NULL || count == k) {
        return;
    }
    // Traverse left subtree
    helperKthSmallest(root->left,count,k,kthSmallest);
    count++;
    if(count == k) {
        kthSmallest = root->val;
        return;
    }
    // // Traverse right subtree
    helperKthSmallest(root->right,count,k,kthSmallest);
}

// Efficient Approach :: Inorder Traversal
// left Root Right :: Sorted Traversal in BST
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int kthSmallest = -1;
    helperKthSmallest(root,count,k,kthSmallest);
    return kthSmallest;
}


int main()
{
    return 0;
}
 
// Kth Largest Element in BST :: GFG


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
    // return dfs[k-1];
    return dfs[dfs.size()-k];
}

// **********************************************************

// T.C. = O(N)
// S.C. = O(H)
// Reverse inorder traversal
// We are traversing from back of inorder which is in decreasing order so we get when count == k for the kth largest
void helperKthLargest(TreeNode* root, int& count, int k, int& kthLargest) {
    if(root == NULL || count == k) {
        return;
    }
    // // Traverse right subtree
    helperKthLargest(root->right,count,k,kthLargest);
    count++;
    if(count == k) {
        kthLargest = root->val;
        return;
    }
    // Traverse left subtree
    helperKthLargest(root->left,count,k,kthLargest);
}

// Efficient Approach :: Inorder Traversal
// left Root Right :: Sorted Traversal in BST
int kthLargest(TreeNode* root, int k) {
    int count = 0;
    int kthLargest = -1;
    helperKthLargest(root,count,k,kthLargest);
    return kthLargest;
}


int main()
{
    return 0;
}

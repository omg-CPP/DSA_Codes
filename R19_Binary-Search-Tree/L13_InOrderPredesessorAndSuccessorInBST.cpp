// Inorder predecessor and successor in BST :: GFG

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

// Inorder Traversal :: O(N)
void helperDFS(TreeNode* root, vector<int>& dfs) {
    if(root == NULL) {
        return;
    }
    helperDFS(root->left,dfs);
    dfs.push_back(root->val);
    helperDFS(root->right,dfs);
}

int predValue(vector<int>& dfs, int key) {
    // Apply Binary Search on the sorted vector :: O(logN)
    // largest value smaller than key
    int lo = 0;
    int hi = dfs.size()-1;
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(dfs[mid] < key) {
            ans = mid;
            lo = mid+1;
        }
        else { // dfs[mid] >= key
            hi = mid-1;
        }
    }
    if(ans != -1) {
        return dfs[ans];
    }
    return -1;
}

int succValue(vector<int>& dfs, int key) {
    // Apply Binary Search on the sorted vector :: O(logN)
    // smallest value greater than key
    int lo = 0;
    int hi = dfs.size()-1;
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(dfs[mid] > key) {
            ans = mid;
            hi = mid-1;
        }
        else { // dfs[mid] <= key
            lo = mid+1;
        }
    }
    if(ans != -1) {
        return dfs[ans];
    }
    return -1;
}

// Helper function to find TreeNode by value
// DFS Traversal :: O(N)
// TreeNode* findNode(TreeNode* root, int val) {

//     if(root == NULL) {
//         return NULL; 
//     }
    
//     if(root->val == val) {
//         return root;
//     }
//     // left call
//     TreeNode* left = findNode(root->left,val);

//     if(left != NULL) {
//         return left;
//     }

//     // right call
//     return findNode(root->right,val);
// }

// Traversing BST :: O(H) = O(logN)
TreeNode* findNode(TreeNode* root, int val) {
    if(root->val == val) {
        return root;
    }
    if(root->val < val) {
        return findNode(root->right,val);
    }
    else { // root->val > val
        return findNode(root->left,val);
    }
}

// T.C. = O(N) + O(logN) + O(logN) + O(logN) + O(logN)
// S.C. = O(N) + O(H) + O(H)
vector<TreeNode*> findPreSuc_Naive(TreeNode* root, int key) {
    vector<TreeNode*> ans(2,NULL); 
    // ans[0] = predecessor, ans[1] = successor

    vector<int> dfs;
    helperDFS(root,dfs);
    

    // Find predecessor (element before key)
    int predVal = predValue(dfs,key);
    if(predVal != -1) {
        ans[0] = findNode(root,predVal);
    }
    
    // Find successor (element after key)
    int succVal = succValue(dfs,key);
    if(succVal != -1) {
        ans[1] = findNode(root,succVal);
    }
    
    return ans;
}

// ****************************************************

// O(H)
void findPredecessor(TreeNode* root, TreeNode*& pred, int key) {
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->val >= key) {
            curr = curr->left;
        }
        else { // curr->val < key
            pred = curr;
            curr = curr->right;
        }
    }
}

// O(H)
void findSuccessor(TreeNode* root, TreeNode*& succ, int key) {
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->val <= key) {
            curr = curr->right;
        }
        else { // curr->val > key
            succ = curr;
            curr = curr->left;
        }
    }
}

// T.C. = O(H)
// S.C. = O(1)
vector<TreeNode*> findPreSuc(TreeNode* root, int key) {
    
    TreeNode* pred = NULL;
    TreeNode* succ = NULL;

    findPredecessor(root,pred,key);
    findSuccessor(root,succ,key);
    
    return {pred,succ};
}


int main()
{
    return 0;
}
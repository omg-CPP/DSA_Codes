// Leetcode : 653

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
// InOrder traversal to get sorted array 
void helperDFS(TreeNode* root, vector<int>& dfs) {
    if(root == NULL) {
        return;
    }
    helperDFS(root->left,dfs);
    dfs.push_back(root->val);
    helperDFS(root->right,dfs);
}

// T.C. = O(N) + O(N)
// S.C. = O(N)
bool findTargetNaive(TreeNode* root, int k) {
    vector<int> dfs;
    helperDFS(root,dfs);
    int lo = 0;
    int hi = dfs.size()-1;
    while(lo < hi) {
        int sum = dfs[lo] + dfs[hi];
        if(sum == k) {
            return true;
        }
        else if(sum < k) {
            lo++;
        }
        else { // sum > k
            hi--;
        }
    }
    return false;
}

// *******************************************

// T.C. = O(N)
// S.C. = O(H)*2
// Optimal Approach :: BST Iterator
class BSTIterator {
private: 
    stack<TreeNode*> st;
    // reverse => true => before
    // reverse => false => next

    bool reverse = true;

    void pushAll(TreeNode* node) {
        while(node != NULL) {
            st.push(node);
            if(reverse == true) { // before
                node = node->right;
            }
            else { // reverse == false  // next
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(reverse == false) {
            pushAll(temp->right);
        }
        else { // reverse == true
            pushAll(temp->left);
        }
        return temp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        // In Order Traversal :: Left Root Right
        BSTIterator l(root,false); // next
        // Reverse In Order Traversal :: Right Root Left
        BSTIterator r(root,true);  // before

        int i = l.next();
        int j = r.next(); // r.before()

        // Two Pointers
        while(i < j) {
            if(i+j == k) {
                return true;
            }
            else if(i+j < k) {
                i = l.next();
            }
            else { // i+j > k
                j = r.next();
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}

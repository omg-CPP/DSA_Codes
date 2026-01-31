// GFG

#include <iostream>
#include <vector>
#include <climits>
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

int findMax(TreeNode* root) {
    TreeNode* curr = root;
    int maxi = INT_MIN;
    while(curr != NULL) {
        maxi = max(maxi,curr->val);
        curr = curr->right;
    }
    return maxi;
}

int findMin(TreeNode* root) {
    TreeNode* curr = root;
    int mini = INT_MAX;
    while(curr != NULL) {
        mini = min(mini,curr->val);
        curr = curr->left;
    }
    return mini;
}

int main()
{
    return 0;
}
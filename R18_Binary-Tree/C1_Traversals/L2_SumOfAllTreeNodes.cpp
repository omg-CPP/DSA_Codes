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

void displayTree(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

int sumTreeNodes(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftSum = sumTreeNodes(root->left);
    int rightSum = sumTreeNodes(root->right);
    int ans = root->val + leftSum + rightSum;
    return ans;
}

int productTreeNodes(TreeNode* root) {
    if(root == NULL) {
        return 1;
    }
    int leftProduct = productTreeNodes(root->left);
    int rightProduct = productTreeNodes(root->right);
    int ans = root->val * leftProduct * rightProduct;
    return ans;
}

int sizeOfTree(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftSize = sizeOfTree(root->left);
    int rightSize = sizeOfTree(root->right);
    int size = 1 + leftSize + rightSize;
    return size;
}

int nodeWithMaxValue(TreeNode* root) {
    if(root == NULL) {
        return INT_MIN;
    }
    int leftMax = nodeWithMaxValue(root->left);
    int rightMax = nodeWithMaxValue(root->right);
    int mx = max(root->val,max(leftMax,rightMax));
    return mx;
}

int nodeWithMinValue(TreeNode* root) {
    if(root == NULL) {
        return INT_MAX;
    }
    int leftMin = nodeWithMinValue(root->left);
    int rightMin = nodeWithMinValue(root->right);
    int mn = min(root->val,min(leftMin,rightMin));
    return mn;
}

int levels(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftLevels = levels(root->left);
    int rightLevels = levels(root->right);
    return 1 + max(leftLevels,rightLevels);
}

// maxDepth Of Binary tree = Levels in a tree 
int maxDepth(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth,rightDepth);
}

// Height of Tree = MaxDepth - 1 = Levels of Tree - 1
int heightOfTree(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    return levels(root)-1;
}

int main()
{
    TreeNode* a = new TreeNode(1); // root node -> a
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    // Connections
    a->left = b; 
    a->right = c;
    b->left = d;    c->left = f;
    b->right = e;   c->right = g;

    // Tree = Recursion
    displayTree(a);
    // 1 2 4 5 3 6 7 

    cout<<endl;

    cout<<sumTreeNodes(a)<<endl; // 28
    cout<<productTreeNodes(a)<<endl; // 5040 = 7!

    cout<<sizeOfTree(a)<<endl; // 7

    cout<<nodeWithMaxValue(a)<<endl; // 7
    cout<<nodeWithMinValue(a)<<endl; // 1

    cout<<levels(a)<<endl; // 3
    cout<<maxDepth(a)<<endl; // 3

    cout<<heightOfTree(a)<<endl; // 2

    return 0;
}
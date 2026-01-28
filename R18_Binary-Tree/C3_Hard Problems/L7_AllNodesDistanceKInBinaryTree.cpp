// Leetcode : 863

#include <iostream>
#include <vector>
#include <unordered_map>
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


void displayTree(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

// BFS
// O(N)
void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parentTrack, TreeNode* target) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left != NULL) {
            parentTrack[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            parentTrack[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

// O(N)
// S.C. = O(N) + O(N) = O(N)
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // node -> parent
    unordered_map<TreeNode*, TreeNode*> parentTrack;
    markParents(root,parentTrack,target);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int currLevel = 0;
    // Second BFS to go upto K level from target node and using our hash table info
    while(!q.empty()) {
        int size = q.size();
        if(currLevel == k) {
            break;
        }
        currLevel++;
        for(int i = 0 ; i < size ; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != NULL && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right != NULL && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parentTrack[curr] != NULL && !visited[parentTrack[curr]]) {
                q.push(parentTrack[curr]);
                visited[parentTrack[curr]] = true;
            }
        }
    }

    vector<int> result;
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }
    return result;
}

int main()
{
    TreeNode* a = new TreeNode(3); // root node -> a
    TreeNode* b = new TreeNode(5);
    TreeNode* c = new TreeNode(1);
    TreeNode* d = new TreeNode(6);
    TreeNode* e = new TreeNode(2);
    TreeNode* f = new TreeNode(0);
    TreeNode* g = new TreeNode(8);
    TreeNode* h = new TreeNode(7);
    TreeNode* i = new TreeNode(4);

    // Connections
    a->left = b;    a->right = c;
    b->left = d;    b->right = e;
    c->left = f;    c->right = g;
    e->left = h;    e->right = i;

    // Tree = Recursion
    displayTree(a);
    // 3 5 6 2 7 4 1 0 8 
    cout<<endl;
    int k = 2;
    vector<int> ans = distanceK(a,b,k);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 7 4 1
    cout<<endl;
    return 0;
}



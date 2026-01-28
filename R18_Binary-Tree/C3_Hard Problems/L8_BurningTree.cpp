// Burning Tree :: GFG

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

// BFS to mark parents pointers and also to return the address of target node
// O(N)
TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parentTrack, int target) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()) {
        TreeNode* curr = q.front();
        if(curr->val == target) {
            res = curr;
        }
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
    return res;
}

// O(N)
int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* start) {
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(start);
    visited[start] = true;
    int time = 0;
    // Second BFS to go upto K level from target node and using our hash table info
    while(!q.empty()) {
        int size = q.size();
        bool flag = false; // Not Burn
        for(int i = 0 ; i < size ; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != NULL && !visited[curr->left]) {
                flag = true;
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right != NULL && !visited[curr->right]) {
                flag = true;
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parentTrack[curr] != NULL && !visited[parentTrack[curr]]) {
                flag = true;
                q.push(parentTrack[curr]);
                visited[parentTrack[curr]] = true;
            }
        }
        if(flag == true) {
            time++;
        }
    }
    return time;
}

// T.C. = O(N) + O(N) = O(N)
// S.C. = O(N) + O(N) = O(N)
int minTime(TreeNode* root, int target) {
    // node -> parent
    unordered_map<TreeNode*, TreeNode*> parentTrack;
    TreeNode* start = markParents(root,parentTrack,target);
    int maxi = findMaxDistance(parentTrack,start);
    return maxi;
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
    int ans = minTime(a,2);
    cout<<ans<<endl; // 4
    return 0;
}
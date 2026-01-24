

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

void displayTree(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

// preOrder : Root Left Right
// inOrder : Left Root Right
// postOrder : Left Right Root
// T.C. = O(3n)
// S.C. = O(4n)
vector<vector<int>> preInPostTraversal(TreeNode* root) {
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    vector<vector<int>> ans;
    vector<int> pre, in, post;
    if(root == NULL) {
        return {{}};
    }
    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if(it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left != NULL) {
                st.push({it.first->left,1});
            }
        }

        // this is part of in
        // increment 2 to 3
        // push right
        else if(it.second == 2) {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right != NULL) {
                st.push({it.first->right,1});
            }
        }

        // don't push it back again
        else {
            post.push_back(it.first->val);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}


int main()
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a->left = b; a->right = e;
    b->left = c; b->right = d;
    e->left = f; e->right = g;

    displayTree(a);
    // 1 2 3 4 5 6 7 
    cout<<endl;

    vector<vector<int>> preInPost = preInPostTraversal(a);
    for(int i = 0 ; i < preInPost.size() ; i++) {
        for(int j = 0 ; j < preInPost[i].size() ; j++) {
            cout<<preInPost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

//        1
//     2     5
//   3  4   6  7

// 1 2 3 4 5 6 7 :: pre
// 3 2 4 1 6 5 7 :: in
// 3 4 2 6 7 5 1 :: post


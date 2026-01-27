// Leetcode : 662

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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


// CBT Indexing
// T.C. = O(N)
// S.C. = O(n)
typedef unsigned long long ll;
int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, ll>> q;
    q.push({root,0});
    int maxWidth = 0;
    while(!q.empty()) {
        int currLevelSize = q.size();
        ll startIdx = q.front().second;
        ll endIdx = q.back().second;

        maxWidth = max(maxWidth, (int)(endIdx-startIdx+1));

        for(int i = 0 ; i < currLevelSize ; i++) {
            TreeNode* node = q.front().first;
            ll idx = q.front().second;
            q.pop();
            if(node->left != NULL) {
                q.push({node->left,2*idx+1});
            }
            if(node->right != NULL) {
                q.push({node->right,2*idx+2});
            }
        }
    }
    return maxWidth;
}


int main()
{
    return 0;
}

// unsigned: Can only store non-negative values (0 and positive numbers)
// Signed means the data type can represent both positive and negative numbers.

// Different integer types and their ranges:

// Type	                 Size	           Range (Power of 2)	Exact Range

// bool                  1 byte
// float                 4 byte
// double                8 byte
// char                  8-bit (1 byte)    -128 to 127
// unsigned char         8-bit (1 byte)    0 to 255
// int	                32-bit (4 byte)   -2³¹ to 2³¹-1	        -2,147,483,648 to 2,147,483,647
// long long	        64-bit (8 byte)   -2⁶³ to 2⁶³-1	        -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
// unsigned int	        32-bit (4 byte)    0 to 2³²-1	         0 to 4,294,967,295
// unsigned long long	64-bit (8 byte)    0 to 2⁶⁴-1	         0 to 18,446,744,073,709,551,615





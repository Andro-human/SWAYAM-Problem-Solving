/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
int depth(TreeNode *root, int height) {
        if (!root) 
            return height;

        int x = 0, y = 0;
        if (root->left)
            x = depth(root->left, height+1);
        if (root->right)
            y = depth(root->right, height+1);
        
        return max(max(x, y), height);
    }

public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return depth(root, 1);
    }
};
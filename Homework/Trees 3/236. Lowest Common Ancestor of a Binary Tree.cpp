/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *res = NULL;
private: 
    bool lowestAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return false;
        
        if (root == p) {
            res = p;
            return true;
        }
        if (root->val == q->val) {
            res = q;
            return true;
        }
        bool x = lowestAncestor(root->left, p, q);
        bool y = lowestAncestor(root->right, p, q);

        if (x && y) { 
            res = root;
        }
        if (!x && !y) 
            return false;
        
        return true;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        lowestAncestor(root, p, q);

        return res;
    }
};
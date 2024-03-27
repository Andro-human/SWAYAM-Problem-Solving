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
    void findBottom(TreeNode* root, int height, int &maxHeight, int &res) {
        if (!root)
            return;
        if (height > maxHeight) {
            maxHeight = height;
            res = root->val;
        }
        findBottom(root->left, height+1 , maxHeight, res);
        findBottom(root->right, height+1, maxHeight, res);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int height = 0, maxHeight = -1;
        int res = 1;
        findBottom(root, height, maxHeight, res);
        return res;
    }
};
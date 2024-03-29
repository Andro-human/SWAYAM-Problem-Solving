class Solution {
private: 
    int diameterOfTree(TreeNode* root, int &res) {
        if (!root)
            return 0;

        int leftHeight = diameterOfTree(root->left, res);
        int rightHeight = diameterOfTree(root->right, res);
        
        if (res < leftHeight+rightHeight) {
            res = leftHeight+rightHeight;
        }

        return max(leftHeight, rightHeight)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameterOfTree(root, res);
        return res;
    }
};
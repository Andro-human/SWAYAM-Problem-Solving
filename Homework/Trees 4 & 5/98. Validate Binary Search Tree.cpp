class Solution {
private: 
    bool isValid(TreeNode* root, long long &prev) {
        if (!root)
            return true;

        bool x = isValid(root->left, prev);
        if (root->val <= prev)
            return false;
        prev = root->val;
        bool y = isValid(root->right, prev);

        return x && y;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return isValid(root, prev);
    }
};
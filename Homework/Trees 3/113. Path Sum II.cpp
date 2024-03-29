class Solution {
private:
    void findPathSum(TreeNode* root, int targetSum, vector<int> &curr, vector<vector<int>> &res) {
        if (!root)
            return;
        
        curr.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(curr);       
            curr.pop_back();
            return;
        }

        findPathSum(root->left, targetSum-root->val, curr, res);
        findPathSum(root->right, targetSum-root->val, curr, res);
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curr;
        findPathSum(root, targetSum, curr, res);
        return res;
    }
};
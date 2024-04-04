class Solution {
private:
    bool findK(TreeNode* root, unordered_set<int> &s, int &k) {
        if (!root)
            return false;

        if (s.find(k-root->val) != s.end())
            return true;
        s.insert(root->val);
        return findK(root->left, s, k) || findK(root->right, s, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return findK(root, s, k);
    }
};
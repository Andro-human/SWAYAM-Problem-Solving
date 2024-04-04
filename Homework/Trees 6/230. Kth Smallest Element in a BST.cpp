class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if (!root || k < 0)
            return -1;
        
        int x = kthSmallest(root->left, k);
        k--;
        if (k == 0) {
            return root->val;
        }
        int y = kthSmallest(root->right, k);

        if (x == -1)
            return y;
        else 
            return x;
    }
};
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        int sum = 0;
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        if (root->val >= low && root->val <= high)
            return sum += root->val;
       
        return sum;
    }
};
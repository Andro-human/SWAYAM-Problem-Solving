class Solution {
    TreeNode* buildTree(vector<int>&nums, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildTree(nums, s, mid-1);
        root->right = buildTree(nums, mid+1, e);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        return buildTree(nums, 0, nums.size()-1);
    }
};
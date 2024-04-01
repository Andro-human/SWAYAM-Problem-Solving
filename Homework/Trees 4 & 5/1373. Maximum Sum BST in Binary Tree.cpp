class TreeInfo {
public:
    bool isBst;
    int minVal;
    int maxVal;
    long long sum;

    TreeInfo(bool isB, int mini, int maxi, int s): isBst{isB}, minVal{mini}, maxVal{maxi}, sum{s} {}
};
class Solution {
private: 
    TreeInfo* maxSum(TreeNode* root, int &res) {
        if (!root) {
            return new TreeInfo(true, INT_MAX, INT_MIN, 0);
        }

        TreeInfo *left = maxSum(root->left, res);
        TreeInfo *right = maxSum(root->right, res);

        if(left->isBst && right->isBst && root->val > left->maxVal && root->val < right->minVal) {
            int sum =  left->sum+right->sum+root->val;
            res = max(sum, res);
            return new TreeInfo(true, min(root->val, left->minVal), max(root->val, right->maxVal), sum);
        }

        if (left->sum > right->sum) {
            return new TreeInfo(false, left->minVal, left->maxVal, left->sum);
        }
        
        return new TreeInfo(false, right->minVal, right->maxVal, right->sum);
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        maxSum(root, res);
        return res;
    }
};
class Solution {
private:
    int pathSumCount(TreeNode* root, int &targetSum, long long currSum, unordered_map<long long,int> &um) {
        if (!root) {
            return 0;
        }
        currSum = currSum + root->val;
        int cnt = 0;
        if (um.find(currSum-targetSum) != um.end()) {
            cnt += um[currSum-targetSum];
        }
        
        um[currSum]++;
        cnt += pathSumCount(root->left, targetSum, currSum, um);
        cnt += pathSumCount(root->right, targetSum, currSum, um);
        um[currSum]--;
        return cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> um;
        um[0] = 1;
        return pathSumCount(root, targetSum, 0, um);
    }
};
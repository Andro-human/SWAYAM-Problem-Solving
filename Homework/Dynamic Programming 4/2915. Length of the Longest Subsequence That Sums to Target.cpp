class Solution {
private:
    // memo
    // int lengthOfLS(int n, vector<int>& nums, int target, vector<vector<int>> &dp) {
    //     if (target == 0) return 0;
    //     if (n < 0 || target < 0) return INT_MIN;

    //     if (dp[n][target] != -1) return dp[n][target];
    //     int x = lengthOfLS(n-1, nums, target-nums[n], dp);
    //     if (x != INT_MIN) x++;
    //     int y = lengthOfLS(n-1, nums, target, dp);
        
    //     return dp[n][target] = max(x,y);
    // }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        // int res = lengthOfLS(n-1, nums, target, dp);
        
        // DP with Space OPMISATION
        dp[0] = 0;
        for (int i=0; i<n; i++) {
            vector<int> temp(target+1, -1); 
            for (int j=0; j<=target; j++) {
                if (j >= nums[i]) {
                    temp[j] = dp[j-nums[i]];
                    if (temp[j] != -1) temp[j]++;
                }
                temp[j] = max(dp[j], temp[j]);
            }
            dp = temp;
        }

        return dp[target];
    }
};
class Solution {
private:
    // Memoisation
    // int maxScore(int mulIdx, int st, int end, vector<int>& nums, vector<int>& multipliers, vector<vector<int>> &dp) {
    //     if (mulIdx >= multipliers.size()) return 0;

    //     if (dp[st][mulIdx] != -1) return dp[st][mulIdx];
    //     int stScore = maxScore(mulIdx+1, st+1, end, nums, multipliers, dp) + (nums[st]*multipliers[mulIdx]);
    //     int endScore = maxScore(mulIdx+1, st, end-1, nums, multipliers, dp) + (nums[end]*multipliers[mulIdx]);
    
    //     return dp[st][mulIdx] = max(stScore, endScore); 
    // }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<int> dp (m+1, 0);

        // Dp with space optimisation
        for(int i=n-1; i>=0; i--) {
            vector<int> temp(m+1, 0);
            for (int j=m-1; j>=i; j--) {
                int end = n-(j-(i-1));
                int stScore = dp[j+1] + (nums[i]*multipliers[j]);        
                int endScore = temp[j+1] + (nums[end]*multipliers[j]);
                temp[j] = max(stScore, endScore);
            }
            dp = temp;
        } 
        return dp[0];
    }
};
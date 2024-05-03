class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);

        dp[n-1] = questions[n-1][0];
        for (int i=n-2; i >= 0; i--) {
            long long take = questions[i][0];
            if (questions[i][1]+i+1 < n) take += dp[i+questions[i][1]+1];

            long long notTake = dp[i+1];
            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};
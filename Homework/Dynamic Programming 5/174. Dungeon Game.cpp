class Solution {
public:
    // DP 
    // int calculateMinimumHP(vector<vector<int>>& dungeon) {
    //     int n = dungeon.size();
    //     int m = dungeon[0].size();

    //     vector<vector<int>> dp(n, (vector<int> (m, INT_MAX)));
    //     dp[n-1][m-1] = 1-dungeon[n-1][m-1];
    //     for (int i=n-1; i>=0; i--) {
    //         for (int j=m-1; j>=0; j--) {
    //             if (dp[i][j] <= 0) dp[i][j] = 1;
    //             if (i-1 >= 0) dp[i-1][j] = min(dp[i-1][j], dp[i][j]-dungeon[i-1][j]);
    //             if (j-1 >= 0) dp[i][j-1] = min(dp[i][j-1], dp[i][j]-dungeon[i][j-1]);
    //         }
    //     }

    //     return dp[0][0];
    // }


    // DP with space optimisation 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
     
        vector<int> dp(m, INT_MAX);
        dp[m-1] = 1-dungeon[n-1][m-1];
        for (int i=n-1; i>=0; i--) {
            vector<int> temp (m, INT_MAX);
            for (int j=m-1; j>=0; j--) {
                if (dp[j] <= 0) dp[j] = 1;
                if (i-1 >= 0) temp[j] = min(temp[j], dp[j]-dungeon[i-1][j]);
                if (j-1 >= 0) dp[j-1] = min(dp[j-1], dp[j]-dungeon[i][j-1]);
            }
            if (i != 0)
                dp = temp;
        }

        return dp[0];
    }
};
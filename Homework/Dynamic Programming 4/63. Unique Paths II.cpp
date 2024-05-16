class Solution {
public:
    // -> DP
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    //     vector<vector<int>> dp (m, vector<int> (n, 0));
    //     if (obstacleGrid[0][0] == 1) return 0;
    //     dp[0][0] = 1;
        
    //     for (int i=0; i<m; i++) {
    //         for (int j=0; j<n; j++) {
    //             if (obstacleGrid[i][j] == 1) {
    //                 dp[i][j] == 0;
    //                 continue;
    //             }
    //             if (i-1 >= 0) dp[i][j] += dp[i-1][j];
    //             if (j-1 >= 0) dp[i][j] += dp[i][j-1];
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }


    // -> DP with space optimisation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp (n, 0);
        if (obstacleGrid[0][0] == 1) return 0;
        for (int i=0; i<m; i++) {
            vector<int> temp (n, 0);
            if (i == 0) temp[0] = 1;
            for (int j=0; j<n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i-1 >= 0) temp[j] += dp[j];
                if (j-1 >= 0) temp[j] += temp[j-1];
            }
            dp = temp;
        }

        return dp[n-1];
    }
};
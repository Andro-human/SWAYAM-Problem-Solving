class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, 0);
        
        for(int i=0; i<n; i++) {
            vector<int> temp (m, INT_MAX);
            temp[0] = grid[i][0];
            for (int j=0; j<m; j++) {
                if (i-1 >= 0) temp[j] = dp[j]+grid[i][j];
                if (j-1 >= 0) temp[j] = min(temp[j], temp[j-1]+grid[i][j]); 
            }
            dp = temp;
        }

        return dp[m-1];
    }
};
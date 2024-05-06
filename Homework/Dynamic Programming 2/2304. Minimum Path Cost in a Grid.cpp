class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp (m);
        for (int i=0; i<m; i++) {
            dp[i] = grid[0][i];
        }
        for (int i=1; i<n; i++) {
            vector<int> temp(m, INT_MAX);
            for (int j=0; j<m; j++) {
                for (int k=0; k<m; k++) 
                    temp[j] = min(temp[j], dp[k]+moveCost[grid[i-1][k]][j]+grid[i][j]);
            }
            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
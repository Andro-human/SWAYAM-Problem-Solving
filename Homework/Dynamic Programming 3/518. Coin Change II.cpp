class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int>(amount+1, -1));
        
        for (int i=0; i<n; i++) {
            dp[i][0] = 1;
        }

        for (int i=0; i<n; i++) {
            for (int j=1; j<=amount; j++) {
                int x = 0;
                if (coins[i] <= j)
                    x = dp[i][j-coins[i]];
                int y = 0;
                if (i>=1)
                    y = dp[i-1][j];
                dp[i][j] = x+y;
            }
        }
        return dp[n-1][amount]; 
    }
};
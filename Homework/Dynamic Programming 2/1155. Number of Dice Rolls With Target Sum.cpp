class Solution {
    int mod = pow(10, 9)+7;
private:    
    // Memoisation
    // int solve(int i, int k, int n, int target, vector<vector<int>> &dp) {
    //     if (target == 0 && i == n+1) return 1;
    //     if (target <= 0 || i > n) return 0;

    //     if (dp[i][target] != -1) return dp[i][target];
    //     int res = 0;
    //     for (int j=1; j<=k; j++) {
    //         res = (res + solve(i+1, k, n, target-j, dp))%mod;
    //     }
    //     return dp[i][target] = res;
    // }
public:
    int numRollsToTarget(int n, int r, int target) {
        // memoisation solution
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return solve(1, r, n, target, dp);   

        //DP with space optimisation solution
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            vector<int> temp (target+1, 0);
            for (int j=0; j<=target; j++) {
                for(int k=1; k<=min(j,r); k++) {
                    temp[j] = (temp[j] + dp[j-k])%mod;
                }
            }    
            dp = temp;
        }

        return dp[target];
    }
};
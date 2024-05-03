class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<int> dp (N, -1);
        
        dp[0] = max(mat[0][0], mat[1][0]);
        dp[1] = max(mat[0][1], max(mat[1][1], dp[0]));
        
        for (int i=2; i<N; i++) {
            int take1st = dp[i-2]+mat[0][i];
            int take2nd = dp[i-2]+mat[1][i];
            int notTake = dp[i-1];
            dp[i] = max(take1st, max(take2nd, notTake));
        }
        
        return dp[N-1];
    }
};
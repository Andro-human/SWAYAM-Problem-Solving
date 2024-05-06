class Solution {
public:
    // DP
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size(), m = text2.size();
    //     vector<vector<int>> dp(n, vector<int>(m, 0));
    //     for (int i=0; i<n; i++) {
    //         for (int j=0; j<m; j++) {
    //             if (text1[i] != text2[j]) {
    //                 if (i-1 >= 0) dp[i][j] = dp[i-1][j];
    //                 if (j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
    //             }
    //             else {
    //                 if (i-1 >=0 && j-1 >= 0) dp[i][j] = dp[i-1][j-1]; 
    //                 dp[i][j]++;
    //             }
    //         }
    //     }

    //     return dp[n-1][m-1];
    // }

    //DP with space optimisation
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> dp (m, 0);
        for (int i=0; i<n; i++) {
            vector<int> temp(m, 0);
            for (int j=0; j<m; j++) {
                if (text1[i] != text2[j]) {
                    if (i-1 >= 0) temp[j] = dp[j];
                    if (j-1 >= 0) temp[j] = max(temp[j], temp[j-1]);
                }
                else {
                    if (i-1 >=0 && j-1 >= 0) temp[j] = dp[j-1]; 
                    temp[j]++;
                }
            }
            dp = temp;
        }

        return dp[m-1];
    }
};
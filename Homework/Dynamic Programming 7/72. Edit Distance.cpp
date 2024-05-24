class Solution {

public:
    // DP 
    // int minDistance(string word1, string word2) {
    //     int n = word1.size(), m = word2.size();
    //     if (n == 0) return m;
    //     if (m == 0) return n;
    //     vector<vector<int>> dp (n, vector<int>(m, -1));

    //     if (word1[0] == word2[0]) dp[0][0] = 0;
    //     else dp[0][0] = 1;
    //     for (int i=0; i<n; i++) {
    //         for (int j=0; j<m; j++) { 
    //             int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    //             if (i-1>=0 && j-1>=0 && word1[i] == word2[j]) {
    //                 dp[i][j] = dp[i-1][j-1];
    //                 continue;
    //             }
    //             if (i-1 < 0 && j-1 < 0) continue;
    //             if (i-1 < 0) x = j+1;
    //             else x = dp[i-1][j];
    //             if (j-1 < 0) y = i+1;
    //             else y = dp[i][j-1];
    //             if (i-1>=0 && j-1>=0) z = dp[i-1][j-1];
    //             dp[i][j] = min(x, min(y,z))+1;
    //         }
    //     }

    //     for (int i=0; i<n; i++) {
    //         for(int j=0; j<m; j++)
    //             cout << dp[i][j] << " ";
    //         cout << endl;
    //     }
    //     return dp[n-1][m-1];
    // }


    // DP with space optimisation
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        vector<int> dp (m+1, -1);

        for (int i=0; i<=m; i++) {
            dp[i] = i;
        }

        for (int i=1; i<=n; i++) {
            vector<int> temp(m+1, -1);
            temp[0] = i;
            for (int j=1; j<=m; j++) { 
                if (word1[i-1] == word2[j-1]) {
                    temp[j] = dp[j-1];
                    continue;
                }
                int x = dp[j];
                int y = temp[j-1];
                int z = dp[j-1];
                temp[j] = min(x, min(y,z))+1;
            }
            dp = temp;
        }

        return dp[m];
    }
};
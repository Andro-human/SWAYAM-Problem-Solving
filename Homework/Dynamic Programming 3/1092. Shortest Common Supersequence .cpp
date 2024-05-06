class Solution {
private:
string lcs(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        vector<vector<int>> dir(n, vector<int> (m, 1));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (str1[i] == str2[j]) {
                    dp[i][j]++;
                    dir[i][j] = 0;
                    if (i-1 >= 0 && j-1 >= 0) {
                        dp[i][j] += dp[i-1][j-1];
                    }
                    continue;
                }
                if (i-1 >= 0) {
                    dp[i][j] = dp[i-1][j];
                    dir[i][j] = 1;
                }
                if (j-1 >= 0 && dp[i][j-1] > dp[i][j]) {
                    dp[i][j] = dp[i][j-1];
                    dir[i][j] = 2;
                }
            }
        }

        int curr = 0;
        string res;
        int i = n-1, j = m-1;
        while (i>=0 && j>=0) {
            curr = dir[i][j];
            if (curr == 0) {
                res += str1[i];
                i--,j--;
            }
            if (curr == 1) {
                res += str1[i];
                i-=1;
            }
            if (curr == 2) {
                res += str2[j];
                j-=1;
            }
        }
        while (j >= 0) res += str2[j--];
        while (i >= 0) res += str1[i--];
        reverse(res.begin(), res.end());
        return res; 
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        return lcs(str1, str2);
    }
};
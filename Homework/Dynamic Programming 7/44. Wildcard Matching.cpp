class Solution {
private:
    // Memoisation solution
    // bool solve(int idxS, int idxP, string &s, string &p, vector<vector<int>> &dp) {
    //     if (idxS >= s.length() && idxP >= p.length()) return true;
    //     if (idxS >= s.length() || idxP >= p.length()) {
    //         if (idxP < p.length() && p[idxP] == '*')
    //             return solve(idxS, idxP+1, s, p, dp);
    //         return false;
    //     }

    //     if (dp[idxS][idxP] != -1) return dp[idxS][idxP];
    //     bool res = false;
    //     if (p[idxP] == '*') {
    //         res = res || solve(idxS+1, idxP, s, p, dp);
    //         res = res || solve(idxS+1, idxP+1, s, p, dp);
    //         res = res || solve(idxS, idxP+1, s, p, dp);
    //     }

    //     if (p[idxP] == '?' || s[idxS] == p[idxP]) {
    //         res = res || solve(idxS+1, idxP+1, s, p, dp);
    //     }

    //     return dp[idxS][idxP] = res;
    // }
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(p.length()+1, false);
        // return solve(0, 0, s, p, dp);

        // DP with space optimisation
        dp[0] = true;
        for (int i=1; i<=p.length(); i++) {
            if (p[i-1] == '*') dp[i] = dp[i-1];
        }
        for (int i=0; i<s.length(); i++) {
            vector<bool> temp(p.length()+1, false);
            for (int j=1; j<=p.length(); j++) {
                if (p[j-1] == '?' || p[j-1] == s[i]) {
                    temp[j] = dp[j-1];
                }
                else if (p[j-1] == '*') {
                    temp[j] = temp[j] || temp[j-1];
                    temp[j] = temp[j] || dp[j];
                    temp[j] = temp[j] || dp[j-1];
                }
            }
            dp = temp;
        }

        return dp[p.length()];
    }
};
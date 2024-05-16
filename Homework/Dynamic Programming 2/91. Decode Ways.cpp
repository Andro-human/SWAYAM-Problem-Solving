class Solution {
private:
    // MEMOISATION
    // int memo(int n, string s, vector<int> &dp) {
    //     if (n == -1) return 1;

    //     // single
    //     if (dp[n] != -1) return dp[n];
    //     int x = 0;
    //     if (s[n] != '0')
    //         x = memo(n-1, s, dp);

    //     // double 
    //     int y = 0;
    //     if (n != 0 && s[n-1] != '0' && s[n-1] <= '2') {
    //         if (s[n-1] == '2' && s[n] > '6') return x;
    //         y = memo(n-2, s, dp);
    //     }

    //     return dp[n] = x+y;
    // }
public:
    int numDecodings(string s) {
        // MEMOISATION SOLUTION
        // vector<int> dp(s.length(), -1);
        // return memo(s.length()-1, s, dp);

        // DP With space optimisation
        int n = s.length();
        int secondPrev = 0;
        int prev = 1;
        for (int i=0; i<n; i++) {
            int x = 0;
            if (s[i] != '0') x = prev;
            int y = 0;
            if (i != 0 && s[i-1] != '0' && s[i-1] <= '2') {
                if (s[i-1] == '2' && s[i] > '6') {}
                else y = secondPrev;
            }
            secondPrev = prev;
            prev = x+y;
        }

        return prev;
    }
};
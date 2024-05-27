class Solution {
    int mod = pow(10,9)+7;
private:
    // Memoisation
    // int solve(int n, int prev, string &s, vector<vector<int>> &dp) {
    //     if (n < 0) {
    //         if (prev != 0)
    //             return 1;
    //         return 0;
    //     }

    //     if (dp[n][prev+1] != -1) return dp[n][prev+1]; 
        
    //     int x = 0, y = 0;

    //     if (s[n] != '*' && prev != 0) {
    //         x = solve(n-1, s[n]-'0', s, dp); 
    //     }
    //     else if (s[n] == '*' && prev != 0) {
    //         for (int i=1; i<10; i++) {
    //             x = (x+solve(n-1, i, s, dp))%mod;
    //         }
    //     }
    //     if (prev != -1 && s[n] != '0') {
    //         int temp = 0;
    //         if (s[n] != '*') {
    //             temp = (s[n]-'0')*10 + prev;
    //             if (temp <= 26) {
    //                 y = solve(n-1, -1, s, dp);
    //             }
    //         }
    //         else {
    //             for (int i=1; i<10; i++) {
    //                 temp = i*10 + prev;
    //                 if (temp <= 26) y = (y+solve(n-1, -1, s, dp))%mod;
    //             }
    //         } 
            
    //     }

    //     return dp[n][prev+1] = (x+y)%mod;
    // }   
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (11, 0));
        // return solve(n-1, -1, s, dp);

        // dp 
        for (int i=-1; i<10; i++) {
            if (i == 0) dp[0][1] = 0;  
            else dp[0][i+1] = 1;
        }

        for (int i=1; i<=n; i++) {
            for (int j=-1; j<10; j++) {
                int x = 0, y = 0;

                if (s[i-1] != '*' && j != 0) {
                    x = dp[i-1][s[i-1]-'0'+1]; 
                }
                else if (s[i-1] == '*' && j != 0) {
                    for (int k=1; k<10; k++) {
                        x = (x+dp[i-1][k+1])%mod;
                    }
                }
                if (j != -1 && s[i-1] != '0') {
                    int temp = 0;
                    if (s[i-1] != '*') {
                        temp = (s[i-1]-'0')*10 + j;
                        if (temp <= 26) {
                            y = dp[i-1][0];
                        }
                    }
                    else {
                        for (int k=1; k<10; k++) {
                            temp = k*10 + j;
                            if (temp <= 26) y = (y+dp[i-1][0])%mod;
                        }
                    } 
                    
                }

                dp[i][j+1] = (x+y)%mod;
            }
        }

        return dp[n][0];
    }
};
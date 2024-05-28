#include <iostream>
#include <vector>
using namespace std;

int mod = 1000000007;

// Memoisation
// int solve(int n, vector<int> &dp) {
//     if (n < 0) return 0;
//     if (n == 0) return 1;
//     if (dp[n] != -1) return dp[n];
//     int res = 0;
//     for(int i=1; i<=6; i++) {
//         res = (res + solve(n-i, dp))%mod;
//     }

//     return dp[n] = res;
// }

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    // cout << solve(n, dp) << endl;

    // DP solution
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=6; j++) {
            if (i-j >=0)
            dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }

    cout << dp[n] << endl;
}
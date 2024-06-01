#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Memoisation
// int minOp(int n, vector<int> &dp) {
//     if (n <= 0) return INT_MAX;
//     if(n == 1) return 0;

//     if (dp[n] != -1) return dp[n];
//     int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    
//     x = minOp(n-1, dp);

//     if (n%2 == 0) y = minOp(n/2, dp);
//     if (n%3 == 0) z = minOp(n/3, dp);

//     dp[n] = min(x, min(y,z));
//     if (dp[n] == INT_MAX) return dp[n];
//     return ++dp[n];
// }

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX);
    // cout << minOp(n, dp);

    // Dp with space optimisation
    dp[1] = 0;
    for (int i=2; i<=n; i++) {
        int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    
        x = dp[i-1];        

        if (n%2 == 0) y = dp[i/2];    
        if (n%3 == 0) z = dp[i/3];        

        dp[i] = min(x, min(y,z));
        if (dp[i] != INT_MAX) dp[i]++;
    }

    cout << dp[n] << endl;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x+1, INT_MAX);

    // DP solution
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        vector<int> temp(x+1, INT_MAX);
        for (int j=0; j<=x; j++) {
            if (j >= coins[i] && temp[j-coins[i]] != INT_MAX) {
                temp[j] = min(dp[j], temp[j-coins[i]]+1);
            }
            else temp[j] = dp[j];
        }

        dp = temp;
    }

    if (dp[x] == INT_MAX) cout << -1 << endl;
    else cout << dp[x] << endl;
}
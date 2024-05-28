#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define mod 1000000007

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x+1, 0);

    // DP solution
    dp[0] = 1;
    for (int i=0; i<n; i++) {
        vector<int> temp(x+1, 0);
        for (int j=0; j<=x; j++) {
            if (j >= coins[i]) {
                temp[j] = (temp[j-coins[i]] + dp[j])%mod;
            }
            else temp[j] = dp[j];
        }
        dp = temp;
    }

    if (dp[x] == INT_MAX) cout << 0 << endl;
    else cout << dp[x] << endl;
}
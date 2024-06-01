#include <iostream>
#include <vector>
using namespace std;

int solve(int s, int e, int n, vector<int> &wines, vector<vector<pair<int,string>>> &dp) {
    if (s > e) return 0;

    if (dp[s][e].first != -1) return dp[s][e].first;
    int currYear = s+n-e; 
    int stScore = solve(s+1, e,n, wines, dp)+(wines[s]*currYear);
    int endScore = solve(s, e-1, n, wines, dp)+(wines[e]*currYear);
    
    if (stScore >= endScore) {
        dp[s][e] = {stScore, "beg"};
    } 
    else dp[s][e] = {endScore, "end"};

    return dp[s][e].first;
}

vector<string> maxProfit(vector<int> &wines) {
    int n = wines.size();
    vector<vector<pair<int,string>>> dp(n, vector<pair<int,string>> (n, {-1,""}));

    solve(0, n-1, n, wines, dp);

    int s = 0, e = n-1;
    vector<string> res;
    while (s <= e) {
        if (dp[s][e].second == "beg") {
            res.push_back("beg");
            s++;
        }
        else {
            res.push_back("end");
            e--;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> wines(n);

    for (int i=0; i<n; i++) cin >> wines[i];

    vector<string> res = maxProfit(wines);
    for (int i=0; i<n; i++) {
        cout << res[i] << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
bool isBipartite(int node, int color, vector<int> &visited, vector<int> adj[], int &cntZero, int &cntOne) {
    visited[node] = color;
    if (color == 0) cntZero++;
    if (color == 1) cntOne++;
    for(auto &i: adj[node]) {
        if (visited[i] == color) return false;
        if (visited[i] == !color) continue;
        
        if (!isBipartite(i, !color, visited, adj, cntZero, cntOne)) return false;
    }

    return true;
}

int power(int n) {
    int num = 1;
    for (int i=0; i<n; i++) {
        num = (num*2)%mod;
    }
    return num;
}

long long solve(int n, int m, vector<int> adj[]) {
    vector<int> visited(n+1, -1);
    long long res = 1;
    for (int i=1; i<=n; i++) {
        if (visited[i] != -1) continue;
        int numZero = 0;
        int numOne = 0;
        if(!isBipartite(i, 0, visited, adj, numZero, numOne)) return 0;
        res = (res * (power(numZero) + power(numOne)))%mod;
    }

    return res;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> adj[n+1];
        for (int i=0; i<m; i++) {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout << solve(n, m, adj) << endl;
    }
}
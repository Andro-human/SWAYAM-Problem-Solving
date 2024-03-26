#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &deckA, vector<int> &deckB, int k) {
    int n = deckA.size(), m = deckB.size();
    vector<long long> prefixA(n+1);
    vector<long long> prefixB(m+1);
    
    prefixA[0] = 0;
    for (int i=1; i<=n; i++) {
        prefixA[i] = deckA[i-1]+prefixA[i-1];
    }

    prefixB[0] = 0;
    for (int i=1; i<=m; i++) {
        prefixB[i] = deckB[i-1]+prefixB[i-1];
    }
    int ans = 0;
    for(int i=0; i<=n; i++) {
        int x = k-prefixA[i];
        if (x < 0) {
            ans = max(ans, i-1);
            break;
        }
        int j = lower_bound(prefixB.begin(), prefixB.end(), x) - prefixB.begin();
        if (j > m || prefixB[j] > x) {
            j--;
        }
        ans = max(ans, i+j);
    }

    cout << ans << endl;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  
  vector<int> deckA(n);
  vector<int> deckB(m);
  
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    deckA[i] = x;
  }

  for(int i=0; i<m; i++) {
    int x;
    cin >> x;
    deckB[i] = x;
  }

  solve(deckA, deckB, k);
}
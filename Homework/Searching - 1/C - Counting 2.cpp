#include <bits/stdc++.h>
using namespace std;

int leastHeight(vector<int> &heights) {
  int q;
  cin >> q;
  
  int res = -1;
  int n = heights.size();
  int s = 0, e = n-1;
  while (s<=e) {
    int mid = s + (e-s)/2;
    
    if (heights[mid] >= q) {
      res = mid;
      e = mid-1;
    }
    else {
      s = mid+1;
    }
  }
  if (res == -1) {
    return 0;
  }
  return n-res;
}

int main() {
  int n, q;
  cin >> n >> q;
  
  vector<int> heights;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    heights.push_back(x);
  }
  sort(heights.begin(), heights.end());
  for(int i=0; i<q; i++) {
    cout << leastHeight(heights) << endl; 
  }
}
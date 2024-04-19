int dfs(int node, vector<int> adj[], int &res) {
    int largest = 0;
    int secondLargest = 0;
    for (auto &i: adj[node]) {
        int x = dfs(i, adj, res); 
        if (largest < x) {  
            secondLargest = largest;
            largest = x;
        }
        else if (secondLargest < x)
            secondLargest = x;
    }
    
    res = max(res, largest+secondLargest);
    return largest+1;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> adj[n];
    int rootIdx = 0;
    for (int i=0; i<n; i++) {
        if (A[i] == -1) {
            rootIdx = i;
            continue;
        }
        adj[A[i]].push_back(i);
    }

    int res = 0;
    dfs(rootIdx, adj, res);
    
    return res;
}
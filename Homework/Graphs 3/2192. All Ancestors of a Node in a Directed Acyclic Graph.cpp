class Solution {
private:
    void dfs(int node, vector<vector<int>> &res, vector<int> adj[], int parent) {
        for(auto &i: adj[node]) {
            if (res[i].size() && res[i].back() == parent) continue;
            res[i].push_back(parent);
            dfs(i, res, adj, parent);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<vector<int>> res(n);
        for (int i=0; i<n; i++) {
            dfs(i, res, adj, i);
        }

        return res;
    }
};
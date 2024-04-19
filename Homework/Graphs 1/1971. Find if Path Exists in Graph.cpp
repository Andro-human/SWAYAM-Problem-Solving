class Solution {
private: 
    void dfs(int node, vector<int> adj[], vector<int> &visited) {
        visited[node] = 1;
        for (auto &i: adj[node]) {
            if (visited[i]) continue;
            visited[i] = 1;
            dfs(i, adj, visited);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> visited (n, 0);
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(source, adj, visited);
        return visited[destination];
    }
};
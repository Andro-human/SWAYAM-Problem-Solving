class Solution
{   
    private:
    int dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &order) {
        visited[node] = true;
        for (auto &i: adj[node]) {
            if (visited[i]) continue;
            dfs(i, visited, adj, order);
        }
        order.push_back(node);
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool> visited(V, false);
        vector<int> order;
        for (int i=0; i<V; i++) {
            if (visited[i]) continue;
            dfs(i, visited, adj, order);
        }
        reverse(order.begin(), order.end());
        
        vector<vector<int>> newAdj(V);
        for (int i=0; i<V; i++) {
            for (auto &j: adj[i]) {
                newAdj[j].push_back(i);
            }
        }
        
        int res = 0;
        visited.assign(V, false);
        vector<int> vec;
        for (auto &i: order) {
            if (visited[i]) continue;
            res++;
            dfs(i, visited, newAdj, vec);
        }
        
        return res;
    }
};
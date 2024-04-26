class Solution {
private: 
    int dfs(int node, vector<bool> &pathVis, vector<bool>&visited, string &color, vector<int> adj[], vector<vector<int>> &store) {
        pathVis[node] = true;
        visited[node] = true;
        store[node][color[node]-'a'] = 1;

        for (auto &i: adj[node]) {
            if (pathVis[i]) return -1;
            if (!visited[i])
                if(dfs(i, pathVis, visited, color, adj, store) == -1) return -1;
            for (int j=0; j<26; j++) {
                store[node][j] = max(store[node][j], store[i][j] + ((color[node]-'a' == j)?1:0));           
            }
        }

        int res = 0;
        for (int i=0; i<26; i++) {
            res = max(res, store[node][i]);
        }
        pathVis[node] = false;
        return res;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> adj[n];
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<bool> visited(n, false);
        vector<bool> pathVis(n ,false);
        vector<vector<int>> store (n, vector<int> (26, 0));

        int parent = 0;
        int res = 0;
        for (int i=0; i<n; i++) {
            if (visited[i]) continue;
            int x = dfs(i, pathVis, visited, colors, adj, store);
            if (x == -1) return -1;
            res = max(res, x);
        }
        return res; 
    }
};
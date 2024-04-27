class Solution {
private:
    int bfs(int src, int dest, int n, unordered_set<int> adj[]) {
        vector<bool> visited(n, false);
        queue<pair<int,int>> q;
        q.push({src, 0});
        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            visited[node] = true;

            if (node == dest) return dist+1;

            for (auto &i: adj[node]) {
                if (visited[i]) continue;
                q.push({i, dist+1});
            }
        }

        return -1;
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        unordered_set<int> adj[n];
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        int res = INT_MAX;
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].erase(edges[i][1]);
            adj[edges[i][1]].erase(edges[i][0]);
            int x = bfs(edges[i][0], edges[i][1], n, adj);
            if (x == -1) continue;
            res = min(res, x);
        }

        if (res == INT_MAX) return -1;
        return res;
    }
};
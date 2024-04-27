class Solution {
    bool bfs(int node, vector<int> &color, vector<vector<int>> &adj) {
        queue<pair<int,int>> q;
        q.push({node, 0});

        while (!q.empty()) {
            int v = q.front().first;
            int currColor = q.front().second;
            q.pop();
            
            color[v] = currColor;
            for (auto &i: adj[v]) {
                if (color[i] == currColor) return false;
                if (color[i] == !currColor) continue;
                q.push({i, !currColor});
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int> color(adj.size(), -1);
    for (int i=0; i<adj.size(); i++) {
        if(color[i] != -1) continue;
        if (!bfs(i, color, adj)) return false; 
    }

    return true;
    }
};
class Solution {
private:
    void dijikstra(vector<pair<int,int>> adj[], vector<int> &distance, int n, vector<int>& disappear) {
        vector<int> visited(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (visited[node]) continue;
            if (dist >= disappear[node]) continue;
            distance[node] = dist;
            visited[node] = true;

            for (auto &i: adj[node]) {
                if (visited[i.first]) continue;
                pq.push({dist+i.second, i.first});
            }
        }

        for (auto &i: distance) if (i == INT_MAX) i = -1;
    }
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> distance(n, INT_MAX);
        dijikstra(adj, distance, n, disappear);
        return distance;
    }
};
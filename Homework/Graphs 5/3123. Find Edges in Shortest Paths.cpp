class Solution {
private: 
    void dijikstra(vector<pair<int,int>> adj[], vector<long long> &distance, int node, int n) {
        vector<bool> visited (n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;       // dist, node
        pq.push({0, node});
        while (!pq.empty()) {
            int currNode = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (visited[currNode]) continue;
            visited[currNode] = true;
            distance[currNode] = dist;

            for (auto &i: adj[currNode]) {
                if (visited[i.first]) continue;
                pq.push({dist+i.second, i.first});
            }
        }
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<long long>sDist(n, INT_MAX);
        vector<long long>dDist(n, INT_MAX);
        dijikstra(adj, sDist, 0, n);
        dijikstra(adj, dDist, n-1, n);

        long long minDist = sDist[n-1];
        vector<bool> res(edges.size(), false);
        for (int i=0; i<edges.size(); i++) {
            long long currDist = sDist[edges[i][0]]+edges[i][2]+dDist[edges[i][1]];
            long long currDist2 = sDist[edges[i][1]]+edges[i][2]+dDist[edges[i][0]];
            if (currDist==minDist || currDist2==minDist) 
                res[i] = true; 
        }

        return res;
    }
};
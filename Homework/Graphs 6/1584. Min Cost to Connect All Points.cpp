class Solution {
private:
    int primsAlgo(vector<pair<int,int>> adj[], int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> visited(n, false);
        int sum = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (visited[node]) continue;
            sum += dist;
            visited[node] = true;
            for (auto &i: adj[node]) {
                if (visited[i.first]) continue;
                pq.push({i.second, i.first});
            }
        }

        return sum;

    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        return primsAlgo(adj, n);
    }
};
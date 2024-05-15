class Solution {
private:
    int dijikstra(vector<pair<int,int>> adj[], vector<int> &distance, int start, int n) {
        vector<int> visited(n+1, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,start});
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (visited[node]) continue;
            distance[node] = dist;
            visited[node] = true;

            for (auto &i: adj[node]) {
                if (visited[i.first]) continue;
                pq.push({dist+i.second, i.first});
            }
        }

        int minTime = INT_MIN;
        for (int i=1; i<=n; i++) {
            if (distance[i] == INT_MAX) return -1;
            minTime = max(minTime, distance[i]);
        }
        return minTime;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0; i<times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> distance(n+1, INT_MAX);
        return dijikstra(adj, distance, k, n);
    }
};
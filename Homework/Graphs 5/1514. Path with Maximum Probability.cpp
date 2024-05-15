class Solution {
private:
    double dijikstra(int n, vector<pair<int,double>> adj[], int startNode, int endNode) {
        vector<int> visited(n, false);
        priority_queue<pair<double,int>> pq;           // prob, node
        pq.push({1.0,startNode});
        while (!pq.empty()) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            if (node == endNode) return prob;
            if (visited[node]) continue;
            visited[node] = true;

            for (auto &i: adj[node]) {
                if (visited[i.first]) continue;
                pq.push({prob*i.second, i.first});
            }

        }

        return 0;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        return dijikstra(n , adj, start_node, end_node);
    }
};
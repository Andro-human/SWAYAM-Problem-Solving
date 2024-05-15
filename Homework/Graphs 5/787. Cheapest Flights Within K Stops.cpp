class Solution {
private:
    int dijikstra(vector<pair<int,int>> adj[], int src, int dst, int k, int n) {
        vector<int> price(n, INT_MAX);
        vector<int> visited(n, INT_MAX);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0, {src, 0}});      // fair, node, level
        visited[src] = 0;
        price[src] = 0;
        while (!pq.empty()) {
            int node = pq.top().second.first;
            int fair = pq.top().first;
            int level = pq.top().second.second;
            pq.pop();

            if (node == dst) return fair;
                        
            for (auto &i: adj[node]) {
                if (level == k && i.first != dst) continue;
                int currFair = i.second+fair; 
                if (level+1 >= visited[i.first] && currFair >= price[i.first]) continue;
                visited[i.first] = level+1;
                price[i.first] = currFair;
                pq.push({currFair, {i.first, level+1}});
            }
        }

        return -1;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];               // node, fair
        for(int i=0; i<flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});    
        } 

        return dijikstra(adj, src, dst, k, n);
    }
};
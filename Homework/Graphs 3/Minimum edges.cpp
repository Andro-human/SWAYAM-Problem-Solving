class Solution{
    private:
        int dijikstra(int src, int dest, int n, vector<pair<int,int>> adj[]) {
            deque<pair<int,int>> dq;
            dq.push_front({src, 0});
            vector<bool> visited (n+1, false);
            int dist = 0;
            while (!dq.empty()) {
                int currNode = dq.front().first;
                dist = dq.front().second;
                dq.pop_front();
                visited[currNode] = true;
                
                if (currNode == dest) return dist;
                
                for (auto &i: adj[currNode]) {
                    if (visited[i.first]) continue;
                    if (i.second == 0) dq.push_front({i.first, i.second+dist});
                    else dq.push_back({i.first, i.second+dist});
                }
                
            }
            
            return -1;
        }
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int,int>> adj[n+1];
            for (int i=0; i<edges.size(); i++) {
                adj[edges[i][0]].push_back({edges[i][1], 0});
                adj[edges[i][1]].push_back({edges[i][0], 1});
            }
            
            return dijikstra(src, dst, n,adj);
        }
};
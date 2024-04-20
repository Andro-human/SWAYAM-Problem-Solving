class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int> &currVisited, vector<int> &visited) {
        visited[node] = 1;
        currVisited[node] = 1;
        for (auto &i: adj[node]) {
            if (currVisited[i]){
                return true;
            }
            if (visited[i]) continue;
            if (dfs(i, adj, currVisited, visited)) return true;
        }
        currVisited[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited (V, 0);
        vector<int> currVisited(V,0);
        for (int i=0; i<V; i++) {
            if (visited[i]) continue;
            if (dfs(i, adj, currVisited, visited)){ 
                return true;
            }
        }
        
        return false;
    }
};
class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int> &visited) {
        visited[node] = 1;
        for (int i=0; i< isConnected.size(); i++) {
            if (!isConnected[node][i] || visited[i]) continue;
            visited[i] = 1;
            dfs(i, isConnected, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> visited (n, 0);
        for (int i=0; i<n; i++) {
            if (visited[i]) continue;
            cnt++;
            dfs(i, isConnected, visited);
        }

        return cnt;   
    }
};
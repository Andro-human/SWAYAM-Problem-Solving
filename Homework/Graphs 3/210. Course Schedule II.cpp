class Solution {
private:
    bool dfs(int node, vector<bool> &pathVis, vector<bool> &visited, vector<int> adj[], vector<int> &res) {
        pathVis[node] = true;
        visited[node] = true;

        for (auto &i: adj[node]) {
            if (pathVis[i]) return true;
            if (visited[i]) continue;
            if (dfs(i, pathVis, visited, adj, res)) return true;
        }
        pathVis[node] = false;
        res.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preReq) {
        vector<int> adj[numCourses];
        for (int i=0; i<preReq.size(); i++) {
            adj[preReq[i][0]].push_back(preReq[i][1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        vector<int> res;
        for (int i=0; i<numCourses; i++) {
            if (visited[i]) continue;
            if (dfs(i, pathVis, visited, adj, res)) return {};
        }

        return res;
    } 
};
class Solution {
private:
    bool detectCycle (int v, vector<vector<int>> &adj, vector<int> &visited, vector<int> &current) {
    visited[v] = 1;
    current[v] = 1;
    
    for (auto &i: adj[v]) {
        if (!visited[i]) {
            if (detectCycle(i, adj, visited, current)){
                current[v] = 0;
                return true;
            };
        }
        else if (current[i]) {
            return true;
        }
    }

    current[v] = 0;
    return false;
}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {       
        vector<vector<int>>adj(numCourses);

        for (auto &i: prerequisites) {
            adj[i[0]].push_back(i[1]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> current(numCourses, 0);
        for (int i=0; i<numCourses; i++) {
                if (!visited[i]) {
                    if(detectCycle(i, adj, visited, current))
                        return false;
                }
        }

        return true;
    }
};
class Solution {
private:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<pair<int,int>>> &roads, vector<vector<int>> &visited) {
        if (i==grid.size()-1 && j == grid[0].size()-1) return true;
        
        visited[i][j] = 1;
        for (auto &k: roads[grid[i][j]-1]) {
            int newRow = i + k.first;
            int newCol = j + k.second;

            if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() || visited[newRow][newCol]) continue;
        
            for (auto &x: roads[grid[newRow][newCol]-1]) {
                if (newRow+x.first != i || newCol+x.second != j) continue;

                if (dfs(newRow, newCol, grid, roads, visited)) return true;               
            }
        }

        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<pair<int,int>>> roads {
            {{0,1}, {0,-1}}, 
            {{1,0},{-1,0}}, 
            {{0, -1}, {1, 0}}, 
            {{1, 0}, {0,1}}, 
            {{-1,0}, {0,-1}}, 
            {{0, 1}, {-1, 0}}};

        return dfs(0,0, grid, roads, visited);
    }
};
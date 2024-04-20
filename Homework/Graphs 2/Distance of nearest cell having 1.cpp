class Solution 
{
    private:
    void bfs(queue<pair<int,int>> &q, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        while (!q.empty()) {
            auto indices = q.front();
            q.pop();

            int row[4] {1,-1,0,0};
            int col[4] {0,0,1,-1};
            for (int i=0; i<4; i++) {
                int newRow = indices.first + row[i];
                int newCol = indices.second + col[i];

                if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] != 0 || visited[newRow][newCol]) continue;

                q.push({newRow, newCol});
                grid[newRow][newCol] = grid[indices.first][indices.second]+1;
                visited[newRow][newCol] = 1;
            }
        }

    }
 
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0)); 
        queue<pair<int,int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    grid[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }

        bfs(q, grid, visited);

        return grid;
	}
};
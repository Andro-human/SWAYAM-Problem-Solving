class Solution {
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        int row[4] {1,-1,0,0};
        int col[4] {0,0,1,-1};

        grid[i][j] = '*';
        for (int k=0; k<4; k++) {
            int newRow = i+row[k];
            int newCol = j+col[k];
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == '0' || grid[newRow][newCol] == '*') continue;
            dfs(grid, newRow, newCol);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '*' || grid[i][j] == '0') continue;
                cnt++;
                dfs(grid, i, j);
            }
        }

        return cnt;
    }
};
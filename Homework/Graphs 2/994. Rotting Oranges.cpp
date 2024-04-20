class Solution {
private:
    int bfs(queue<pair<pair<int,int>, int>> &q, vector<vector<int>>& grid, int &cntFresh) {
        int currentTime = 0;
        while (!q.empty()) {
            auto indices = q.front().first;
            currentTime = q.front().second;
            q.pop();

            int row[4] {1,-1,0,0};
            int col[4] {0,0,1,-1};
            for (int i=0; i<4; i++) {
                int newRow = indices.first + row[i];
                int newCol = indices.second + col[i];

                if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] != 1) continue;

                q.push({{newRow, newCol}, currentTime+1});
                cntFresh--;
                grid[newRow][newCol] = 3;
            }
        }

        return currentTime;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int cntFresh = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    grid[i][j] = 3;
                }
                if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        int minutes = bfs(q, grid, cntFresh);
        
        if(cntFresh) return -1;
        return minutes;
    }
};
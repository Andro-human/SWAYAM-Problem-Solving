int Solution::knight(int n, int m, int i, int j, int x, int y) {
    int xAxis[8] {2,1,2,1,-2,-1,-2,-1};
    int yAxis[8] {1,2,-1,-2, 1,2,-1,-2};
    
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    queue<pair<pair<int,int>, int>> q;
    q.push({{i,j}, 0});
    visited[i][j] = true;
    
    while (!q.empty()) {
        auto idx = q.front().first;
        int moves = q.front().second;
        q.pop();
        
        if (idx.first == x && idx.second == y) return moves;
        for (int k=0; k<8; k++) {
            int row = idx.first + xAxis[k];
            int col = idx.second + yAxis[k];
            
            if (row < 1 || row > n || col < 1 || col > m || visited[row][col]) continue;
            
            q.push({{row, col}, moves+1});
            visited[row][col] = true;
        }
    }
    
    return -1;
}

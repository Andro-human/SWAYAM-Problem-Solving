bool isInsideCircle(int x, int y, int n, int r, vector<int> &E, vector<int> &F) {
    r = pow(r,2);
    for (int i=0; i<n; i++) {
        int circleX = E[i];
        int circleY = F[i];                   
        
        int distX = pow(x-circleX, 2);
        int distY = pow(y-circleY, 2);
        
        int dist = distX+distY;
        
        if (dist <= r) {
            return true;
        }
    }
    
    return false;
}

bool dfs(int srcX, int srcY, int &destX, int &destY, int n, int r, vector<int> &E, vector<int> &F, vector<vector<bool>> &visited) {
    if (srcX == destX && srcY == destY) return true;
    visited[srcX][srcY] = true;
    int xAxis[8] {1,1, 0, -1,-1,-1, 0, 1};
    int yAxis[8] {0, 1, 1, 1, 0, -1, -1, -1};
    
    for (int i=0; i<8; i++) {
        int newX = srcX+xAxis[i];
        int newY = srcY+yAxis[i];
        if (newX < 0 || newY < 0 || newX>destX || newY>destY || visited[newX][newY]) continue;
        if (isInsideCircle(newX, newY, n, r, E, F)) continue;        
    
        if (dfs(newX, newY, destX, destY, n, r, E, F, visited)) return true; 
    }
    
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    if (isInsideCircle(0, 0, C, D, E, F)) return "NO";      
    vector<vector<bool>> visited (A+1, vector<bool>(B+1, false));
    if (dfs(0,0 , A,B, C, D, E, F, visited)) return "YES";
    return "NO";
}

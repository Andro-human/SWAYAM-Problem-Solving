class Solution {
private:
     void dfs(int i, int j, vector<vector<char>>& board, char c) {
        int row[4] {1,-1,0,0};
        int col[4] {0,0,1,-1};
        board[i][j] = c;

        for(int k=0; k<4; k++) {
            int newRow = i+row[k];
            int newCol = j+col[k];
            if (newRow < 0 || newCol < 0 || newRow >= board.size() || newCol >=board[0].size() || board[newRow][newCol] == '1' || board[newRow][newCol] == 'X') continue;
            dfs(newRow, newCol, board, c);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for (int i=0; i<m; i++) {
            if (board[0][i] == 'O') 
                dfs(0, i, board, '1');
            
            if (board[n-1][i] == 'O') 
                dfs(n-1, i, board, '1');
        }
        for (int i=0; i<n; i++) {
            if (board[i][0] == 'O') 
                dfs(i, 0, board, '1');

            if (board[i][m-1] == 'O') 
                dfs(i, m-1, board, '1');
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == 'X') continue;
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                    continue;
                }
                dfs(i, j, board, 'X');
            }
        }
    }
};
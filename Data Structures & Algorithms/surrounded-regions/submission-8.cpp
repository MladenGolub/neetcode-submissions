class Solution {

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int j = 0; j < cols; j++) {
            dfs(board, 0, j, visited);

            dfs(board, rows-1, j, visited);
        }

        for(int i = 0; i < rows; i++) {
            dfs(board, i, 0, visited);

            dfs(board, i, cols - 1, visited);
        }

        for(int i = 1; i < rows-1; i++) {
            for(int j = 1; j < cols-1; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

    }


    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited) {

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited[r][c] || board[r][c] == 'X') {
            return;
        }

        visited[r][c] = true;

        for(int i = 0; i < 4; i++) {
            dfs(board, r + dir[i][0], c + dir[i][1], visited);
        }

    }
};

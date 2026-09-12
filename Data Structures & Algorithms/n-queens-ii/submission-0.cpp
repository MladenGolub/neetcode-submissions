class Solution {
public:
    int totalNQueens(int n) {
        
        int cnt = 0;
        vector<string> board(n, string(n, '.'));
        backtrack(0, board, cnt);
        return cnt;

    }
    
    void backtrack(int r, vector<string> board, int& cnt) {
        if(r == board.size()) {
            cnt++;
            return;
        }
        for(int c = 0; c < board.size(); c++) {
            if(isSafe(r, c, board)) {
                board[r][c] = 'Q';
                backtrack(r + 1, board, cnt);
                board[r][c] = '.';
            }
        }
    }

    bool isSafe(int r, int c, vector<string>& board) {
        for(int i = r - 1; i >= 0; i--) {
            if(board[i][c] == 'Q') return false;
        }
        for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};
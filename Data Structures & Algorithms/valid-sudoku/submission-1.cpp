class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                char pom = board[i][j];//uzeli smo el
                if(pom == '.') continue;
                for(int k = 0; k < board[i].size(); k++) {
                    if(j != k && board[i][k] == pom) {
                        return false;
                    }
                }//for za red
                for(int k = 0; k < board.size(); k++) {
                    if(i != k && board[k][j] == pom) {
                        return false;
                    }
                }//for za kolonu
                if(i % 3 == 0) {
                    if(j % 3 == 0) {
                        if(board[i][j] == board[i][j+1] || board[i][j] == board[i][j+2]) return false;
                        if(board[i][j] == board[i+1][j] || board[i][j] == board[i+1][j+1] || board[i][j] == board[i+1][j+2]) return false;
                        if(board[i][j] == board[i+2][j] || board[i][j] == board[i+2][j+1] || board[i][j] == board[i+2][j+2]) return false;
                    } else if(j % 3 == 1) {
                        if(board[i][j] == board[i][j-1] || board[i][j] == board[i][j+1]) return false;
                        if(board[i][j] == board[i+1][j-1] || board[i][j] == board[i+1][j] || board[i][j] == board[i+1][j+1]) return false;
                        if(board[i][j] == board[i+2][j-1] || board[i][j] == board[i+2][j] || board[i][j] == board[i+2][j+1]) return false;
                    } else {
                        if(board[i][j] == board[i][j-1] || board[i][j] == board[i][j-2]) return false;
                        if(board[i][j] == board[i+1][j-2] || board[i][j] == board[i+1][j-1] || board[i][j] == board[i+1][j]) return false;
                        if(board[i][j] == board[i+2][j-2] || board[i][j] == board[i+2][j-1] || board[i][j] == board[i+2][j]) return false;
                    }
                } else if(i % 3 == 1) {
                    if(j % 3 == 0) {
                        if(board[i][j] == board[i-1][j] || board[i][j] == board[i-1][j+1] || board[i][j] == board[i-1][j+2]) return false;
                        if(board[i][j] == board[i][j+1] || board[i][j] == board[i][j+2]) return false;
                        if(board[i][j] == board[i+1][j] || board[i][j] == board[i+1][j+1] || board[i][j] == board[i+1][j+2]) return false;
                    } else if(j % 3 == 1) {
                        if(board[i][j] == board[i-1][j-1] || board[i][j] == board[i-1][j] || board[i][j] == board[i-1][j+1]) return false;
                        if(board[i][j] == board[i][j-1] || board[i][j] == board[i][j+1]) return false;
                        if(board[i][j] == board[i+1][j-1] || board[i][j] == board[i+1][j] || board[i][j] == board[i+1][j+1]) return false;
                    } else {
                        if(board[i][j] == board[i-1][j-2] || board[i][j] == board[i-1][j-1] || board[i][j] == board[i-1][j]) return false;
                        if(board[i][j] == board[i][j-2] || board[i][j] == board[i][j-1]) return false;
                        if(board[i][j] == board[i+1][j-2] || board[i][j] == board[i+1][j-1] || board[i][j] == board[i+1][j]) return false;
                    }
                } else {
                    if(j % 3 == 0) {
                        if(board[i][j] == board[i-2][j] || board[i][j] == board[i-2][j+1] || board[i][j] == board[i-2][j+2]) return false;
                        if(board[i][j] == board[i-1][j] || board[i][j] == board[i-1][j+1] || board[i][j] == board[i-1][j+2]) return false;
                        if(board[i][j] == board[i][j+1] || board[i][j] == board[i][j+2]) return false;
                    } else if(j % 3 == 1) {
                        if(board[i][j] == board[i-2][j-1] || board[i][j] == board[i-2][j] || board[i][j] == board[i-2][j+1]) return false;
                        if(board[i][j] == board[i-1][j-1] || board[i][j] == board[i-1][j] || board[i][j] == board[i-1][j+1]) return false;
                        if(board[i][j] == board[i][j-1] || board[i][j] == board[i][j+1]) return false;
                    } else {
                        if(board[i][j] == board[i-2][j-2] || board[i][j] == board[i-2][j-1] || board[i][j] == board[i-2][j]) return false;
                        if(board[i][j] == board[i-1][j-2] || board[i][j] == board[i-1][j-1] || board[i][j] == board[i-1][j]) return false;
                        if(board[i][j] == board[i][j-2] || board[i][j] == board[i][j-1]) return false;
                    }
                }
            }
        }//uzimam jedan po jedan el. tj jedno po jedno mesto

        return true;

    }
};

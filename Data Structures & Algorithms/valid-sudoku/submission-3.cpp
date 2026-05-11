class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Elegantnije rješenje - ista O(1) složenost
        unordered_set<string> seen;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                char c = board[i][j];
                string row   = to_string(i) + "r" + c;
                string col   = to_string(j) + "c" + c;
                string block = to_string(i/3) + "b" + to_string(j/3) + c;
                if(!seen.insert(row).second ||
                !seen.insert(col).second ||
                !seen.insert(block).second)
                    return false;
            }
        }
        return true;
    }
};

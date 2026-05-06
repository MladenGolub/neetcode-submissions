class Solution {

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dp;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(); int col = matrix[0].size();
        dp = vector<vector<int>>(rows, vector<int>(col, -1));//popunimo je nulama za sada
        int res = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                res = max(res, dfs(matrix, i, j, INT_MIN));
            }
        }

        return res;

    }   

    int dfs(vector<vector<int>> matrix, int r, int c, int prevVal) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        if (r < 0 || r >= ROWS || c < 0 ||
            c >= COLS || matrix[r][c] <= prevVal) {
            return 0;
        }
        if (dp[r][c] != -1) return dp[r][c];

        int res = 1;
        for (vector<int> d : directions) {
            res = max(res, 1 + dfs(matrix, r + d[0],
                               c + d[1], matrix[r][c]));
        }
        dp[r][c] = res;
        return res;
    }
};

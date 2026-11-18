class Solution {

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(col, false));
        vector<vector<bool>> atl(rows, vector<bool>(col, false));
        vector<vector<int>> ret;

        for(int c = 0; c < col; c++) {
            dfs(heights, 0, c, pac, heights[0][c]);//prosledjujemo grid, nulti red i redom kolone, zajedno sa tr visino
            dfs(heights, rows-1, c, atl, heights[rows-1][c]);
        }

        for(int r = 0; r < rows; r++) {
            dfs(heights, r, 0, pac, heights[r][0]);//prosledjujemo grid, nulti red i redom kolone, zajedno sa tr visino
            dfs(heights, r, col-1, atl, heights[r][col - 1]);
        }


        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited, int prevHeight) {

        if(r < 0 || c < 0 || r == heights.size() || c == heights[0].size() || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        visited[r][c] = true;

        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            dfs(heights, nr, nc, visited, heights[r][c]);
        }

    }
};

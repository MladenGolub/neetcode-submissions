class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int res = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    res += backtrack(grid, i, j, 1);
                }
            }
        }

        return res;

    }

    int backtrack(vector<vector<int>>& grid, int r, int c, int prev) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            if(prev == 1) return 1;
            else return 0;
        } 
        if (grid[r][c] == -1) {
            return 0;
        }
        if(grid[r][c] == 0) {
            return 1;
        }

        int tmp = grid[r][c];
        grid[r][c] = -1;

        int res = 0;

        res += backtrack(grid, r + 1, c, tmp);
        res += backtrack(grid, r - 1, c, tmp);
        res += backtrack(grid, r, c + 1, tmp);
        res += backtrack(grid, r, c - 1, tmp);
        
        return res;
    }
};





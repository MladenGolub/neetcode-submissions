class Solution {

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        int pom = 0;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < col; c++) {
                if(grid[r][c] == 1) {
                    pom = bfs(grid, r, c);
                    if(pom > maxArea) maxArea = pom;
                }
            }
        }

        return maxArea;

    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int,int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        int cnt = 1;

        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            for(int i = 0; i < 4; i++) {
                int nrow = row + directions[i][0];
                int ncol = col + directions[i][1];
                if(nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                ncol < grid[0].size() && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 0;
                    cnt++;
                }
            }
        }

        return cnt;
    }





};

class Solution {

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        bfs(grid, q);

    }

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {

        int rows = grid.size();
        int col = grid[0].size();
        int cnt = 1;

        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                size--;
                for(int i = 0; i < 4; i++) {
                    int nrow = r + directions[i][0];
                    int ncol = c + directions[i][1];
                    if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < col && grid[nrow][ncol] == INT_MAX) {
                        if(grid[nrow][ncol] > cnt) grid[nrow][ncol] = cnt;
                        q.push({nrow, ncol});
                        //obisao.insert({nrow, ncol});
                    }
                }
            }
            cnt++;
        }
    }
};

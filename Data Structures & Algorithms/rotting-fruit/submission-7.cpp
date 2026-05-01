class Solution {

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //ako krenemo od pokvarenog voca i idemo ka zdravom, i kada zavrzimo ciklus ceo za pokvareno voce cnt uvecamo

        int rows = grid.size();
        int col = grid[0].size();
        int zdrave = 0;
        queue<pair<int, int>> q;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < col; c++) {
                if(grid[r][c] == 2) {//ako je pokvareno voce ubacujemo ga u red
                    q.push({r, c});
                } else if(grid[r][c] == 1) {
                    zdrave++;
                }
            }
        }
        // if(q.empty() && zdrave == 0) return 0;
        // else if(q.empty() && zdrave != 0) return -1;
        return bfs(grid, q, zdrave);
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>> q, int zdrave) {
        
        int cnt = 0;
        int rows = grid.size();
        int col = grid[0].size();

        while(!q.empty()) {
            int size = q.size();
            bool changed = false;
            for(int i = 0; i < size; i++) {
                pair<int,int> node = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int nr = node.first + dir[j][0];
                    int nc = node.second + dir[j][1];
                    if(nr >= 0 && nc >= 0 && nr < rows && nc < col && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        zdrave--;
                        changed = true;
                        q.push({nr, nc});
                    }
                }
            }
            if(changed) cnt++;
        }
        // if(zdrave == 0) {
        //     if(cnt == 1) {
        //         return 0;
        //     } else {
        //         return cnt-1;
        //     }
        // } else {
        //     return -1;
        // }
        return zdrave == 0 ? cnt : -1;
        
    }
};

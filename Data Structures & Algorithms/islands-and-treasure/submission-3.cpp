class Solution {

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    //set<pair<int, int>> obisao;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        
        int rows = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < col; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});//ova funkcija ce promeniti vrednost ,a mestu r c ili nece, ako ne moze da se dodje do blaga od zadatog mesta
                }
            }
        }
        bfs(grid, q);

    }

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        
        int inf = (1LL << 31) - 1;
        int cnt = 1;
        int rows = grid.size();
        int col = grid[0].size();

        //obisao.insert({q.front().first, q.front().second});

        while(!q.empty()) {
            int size = q.size();
            for(int j = 0; j < size; j++) {
                pair<int, int> node = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nrow = node.first + directions[i][0];
                    int ncol = node.second + directions[i][1];
                    if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < col && grid[nrow][ncol] == inf) {
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

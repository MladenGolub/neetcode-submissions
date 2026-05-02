class Solution {

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int,int>> q;
    set<pair<int,int>> neograniceni;
public:
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int col = board[0].size();

        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O') { board[i][0] = 'N'; q.push({i, 0}); neograniceni.insert({i, 0}); }
            if(board[i][col-1] == 'O') { board[i][col-1] = 'N'; q.push({i, col - 1}); neograniceni.insert({i, col - 1}); }
        }
        
        for(int i = 0; i < col; i++) {
            if(board[0][i] == 'O') { board[0][i] = 'N'; q.push({0, i}); neograniceni.insert({0, i}); }
            if(board[rows-1][i] == 'O') { board[rows-1][i] = 'N'; q.push({rows-1, i}); neograniceni.insert({rows-1, i}); }
        }
        //trebalo bi da smo dohvatili sve O koji se nalaze na ivicama

        bfs(board, q);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O' && neograniceni.find({i, j}) == neograniceni.end()) {
                    board[i][j] = 'X'; 
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'N') {
                    board[i][j] = 'O'; 
                }
            }
        }
    }     

    void bfs(vector<vector<char>>& board, queue<pair<int, int>> q) {

        int rows = board.size();
        int col = board[0].size();
        
        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
        
            for(int i = 0; i < 4; i++) {
                int nr = node.first + dir[i][0];    
                int nc = node.second + dir[i][1];   
                if(nr >= 0 && nc >=0 && nr < rows && nc < col && board[nr][nc] == 'O') {
                    q.push({nr, nc});
                    board[nr][nc] = 'N';
                    neograniceni.insert({nr, nc});
                }
            }
        }
        

    }
};

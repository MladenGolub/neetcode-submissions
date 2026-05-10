class Solution {

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dp;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));//popunimo je nulama za sada
        int res = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                res = max(res, dfs(i, j, matrix, INT_MIN));
            }
        }

        return res;

    }   

    int dfs(int i, int j, vector<vector<int>>& matrix, int prevValue) {

        if(i >= matrix.size() || j >= matrix[0].size() || i < 0 || j < 0 || matrix[i][j] <= prevValue) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int pom = 1;

        for(int k = 0; k < 4; k++) {
            int novoI = i + directions[k][0];
            int novoJ = j + directions[k][1];
            
            pom = max(pom, 1+dfs(novoI, novoJ, matrix, matrix[i][j]));
            
        }
        dp[i][j] = pom;
        return pom;

    }
};

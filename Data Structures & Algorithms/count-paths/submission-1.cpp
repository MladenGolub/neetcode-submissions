class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp2(m, vector<int>(n, 0));

        dp2[m-1][n-1] = 1;//ovo je poslednje polje stavicemo mu jedan da nam radi alg
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) continue;
                if(j + 1 < n) dp2[i][j] += dp2[i][j+1];
                if(i + 1 < m) dp2[i][j] += dp2[i+1][j];
            }
        }

        return dp2[0][0];

    }
};

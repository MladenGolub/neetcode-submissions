class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp2(m, vector<int>(n, 1));
        
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                dp2[i][j] = dp2[i+1][j] + dp2[i][j+1];
            }
        }

        return dp2[0][0];

    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

        //glvani uslov mi je da li je j stiglo do kraja jer ako jeste mi smo nasli string koji odgovara stringu t

        return dfs(0, 0, s, t, dp);

    }

    int dfs(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if(j >= t.size()) {
            return 1;
        }
        if(i >= s.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        if(s[i] == t[j]) {
            res += dfs(i+1, j+1, s, t, dp);
            res += dfs(i+1, j, s, t, dp);
        } else {
            res += dfs(i+1, j, s, t, dp);
        }
        dp[i][j] = res;
        return dp[i][j];
    }
};

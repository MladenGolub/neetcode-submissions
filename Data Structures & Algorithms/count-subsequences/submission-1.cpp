class Solution {
public:
    int numDistinct(string s, string t) {
        
        if(t.size() > s.size()) return 0;

        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

        return dfs(0, 0, s, t, dp);

    }

    int dfs(int i, int j, string s, string t, vector<vector<int>>& dp) {

        if(j == t.size()) return 1;//stigli smo do kraja t znaci nasli smo podstirng

        if(i == s.size()) return 0;//stigli smo do kraja s, znaci nismo nasli podstring

        if(dp[i][j] != -1) return dp[i][j];//ako smo kombinaciju vec obisli, samo vracamo ono sto smo za nju izracunali

        if(s[i] == t[j]) {
            dp[i][j] = dfs(i+1, j+1, s, t, dp) + dfs(i+1, j, s, t, dp);
        } else {
            dp[i][j] = dfs(i+1, j, s, t, dp);
        }

        return dp[i][j];

    }

};

class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));

        return dfs(0, 0, dp, s, p);

    }

    bool dfs(int i, int j, vector<vector<int>>& dp, string s, string p) {

        if(j == p.size()) return i == s.size();

        if(dp[i][j] != -1) return dp[i][j];

        bool match = false; 

        if(i < s.size()) {
            match = (s[i]==p[j]) || p[j] == '.';//imacemo match ako su isti ili ako je u p . jer tacka znaci bilo koji karakter    
        } 

        if((j+1) < p.size() && (p[j+1] == '*')) {
            dp[i][j] = dfs(i, j+2, dp, s, p) || (match && dfs(i+1, j, dp, s, p));//mozemo da ne iskoristimo zvezdu, ili ako je imamo i imamo match da iskoristimo tu zvezdu tako sto uzmemo 
            //taj karakter barem jednom
            return dp[i][j];
        }
        if(match) {
            dp[i][j] = dfs(i+1, j+1, dp, s, p);
            return dp[i][j];
        }

        dp[i][j] = false;
        return false;//ako se nista od toga nije ispunilo

    }
};

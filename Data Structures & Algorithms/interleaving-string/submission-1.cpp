class Solution {

    vector<vector<int>> dp;

public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) return false;
        
        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        dp[s1.size()][s2.size()] = 1;

        return dfs(0, 0, s1, s2, s3);

    }

    bool dfs(int i, int j, string s1, string s2, string s3) {

        if(i == s1.size() && j == s2.size()) {
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        bool res = false;

        if(i < s1.size() && s1[i] == s3[i+j]) res = dfs(i+1, j, s1, s2, s3);

        if(j < s2.size() && s2[j] == s3[i+j]) res = dfs(i, j + 1, s1, s2, s3);

        dp[i][j] = res;
        return res;

    }
};

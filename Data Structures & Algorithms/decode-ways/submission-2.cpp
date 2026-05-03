class Solution {
public:
    int dfs(int i, string& s, unordered_map<int, int>& dp) {
        if(dp.count(i)) return dp[i];
    
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s, dp);
        if (i < s.size() - 1) {
            if (s[i] == '1' ||
               (s[i] == '2' && s[i + 1] < '7')) {
                res += dfs(i + 2, s, dp);
            }
        }
        dp[i] = res;
        return res;
    }

    int numDecodings(string s) {
        
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        
        return dfs(0, s, dp);
    }
};
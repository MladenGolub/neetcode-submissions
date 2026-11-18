class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        return dfs(n, n, dp);

    }

    int dfs(int num, int original, vector<int>& dp) {
        if(dp[num] != -1) return dp[num];

        dp[num] = (num == original) ? 0 : num;
        for(int i = 1; i < num; i++) {
            int val = dfs(i, original, dp) * dfs(num - i, original, dp);
            dp[num] = max(dp[num], val);
        }

        return dp[num];
    }
};
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(piles);                 // dp[i][i] = piles[i]
        for (int i = n - 2; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                dp[j] = max(piles[i] - dp[j],      // dp[j]   je još dp[i+1][j]
                            piles[j] - dp[j - 1]); // dp[j-1] je već dp[i][j-1]
        return dp[n - 1] > 0;

    }

};
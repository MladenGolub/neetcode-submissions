class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {
                if(j == 0) {
                    //ako sam u 0 to je stanje kupovine
                    int buy = dp[i+1][1] - prices[i];
                    int cool = dp[i+1][j];
                    dp[i][j] = max(buy, cool);
                } else {
                    int sell = (i + 2 < prices.size()) ? dp[i+2][0] + prices[i] : prices[i];
                    int cool = dp[i+1][j];
                    dp[i][j] = max(sell, cool);
                }
            }
        }

        return dp[0][0];
    }
};

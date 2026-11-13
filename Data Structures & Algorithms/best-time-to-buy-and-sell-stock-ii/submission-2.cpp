class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return rec(prices, 0, 0, dp);
    }

private:

    int rec(vector<int>& prices, int i, int kupovao, vector<vector<int>>& dp) {
        if(i == prices.size()) {
            return 0;
        }

        if(dp[i][kupovao] != -1) {
            return dp[i][kupovao];
        }

        int res = rec(prices, i+1, kupovao, dp);//samo preskacemo ni ne kupujemo ni ne prodajemo, gledamo koja ce vrednosti biti u tom slucaju
        if(kupovao == 1) {//ako smo prodavali, sada cemo da kupujemo
            res = max(res, prices[i] + rec(prices, i + 1, 0, dp));
        } else {
            res = max(res, -prices[i] + rec(prices, i + 1, 1, dp));
        }
        dp[i][kupovao] = res;
        return res;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int maxProfit = 0;
        int l = 0;
        int r = 1;

        while(l < prices.size() && r < prices.size()) {
            profit = prices[r] - prices[l];
            if(maxProfit < profit) {
                maxProfit = profit;
            }
            if(prices[l] > prices[r]) {
                l = r;
                r = r + 1;
            } else {
                r = r + 1;
            }
        }

        return maxProfit;
    }
};

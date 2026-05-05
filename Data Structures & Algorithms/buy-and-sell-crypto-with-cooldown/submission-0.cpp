class Solution {

    unordered_map<string, int> dp;

public:
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }

    int dfs(int i, bool buying, vector<int>& prices) {
        if(i >= prices.size()) return 0;

        string key = to_string(i) + "-" + to_string(buying);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }

        int cooldown = dfs(i+1, buying, prices);
        if(buying) {
            int buy = dfs(i + 1, false, prices) - prices[i];
            dp[key] = max(buy, cooldown);//zelim da vidimo sta je bolje po nas, da preskocimo transakciju taj dan ili da kupimo
        } else {
            int sell = dfs(i + 2, true, prices) + prices[i];
            dp[key] = max(sell, cooldown);
        }

        return dp[key];
    }
};

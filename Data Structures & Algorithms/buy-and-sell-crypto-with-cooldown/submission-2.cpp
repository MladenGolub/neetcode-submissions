class Solution {

    unordered_map<string, int> dp;

public:
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }

    int dfs(int index, bool buying, vector<int>& prices) {
        if(index >= prices.size()) return 0;

        string key = to_string(index) + "" + to_string(buying);//pravim kljuc, a kljuc ce biti za svaki element tj za njegov index da li u tom stanju kupuje ili prodaje

        if(dp.find(key) != dp.end()) {
            return dp[key];
        }

        int cooldown = dfs(index + 1, buying, prices);//ako smo samo preskocili 
        if(buying) {
            int buy = dfs(index + 1, false, prices) - prices[index];//ako smo kupili ovo nam je trenutni profit
            dp[key] = max(cooldown, buy);
        } else {
            int sell = dfs(index + 2, true, prices) + prices[index];//ako smo prodali moramo da stavimo index + 2 jer cemo tako osigurati da se posle sell ne radi buy nego ide cooldown
            dp[key] = max(cooldown, sell);
        }

        return dp[key];
    }
};

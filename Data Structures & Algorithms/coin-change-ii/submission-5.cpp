class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));

        for(int i = 0; i < coins.size(); i++) {
            dp[i][amount] = 1;//poslednja kolona su sve jedinice
        }

        sort(coins.begin(), coins.end());

        for(int i = coins.size() - 1; i >= 0; i--) {
            for(int j = amount-1; j >= 0; j--) {
                if((amount - j) - coins[i] >= 0) {
                    if(i+1 < coins.size()) {
                        dp[i][j] = dp[i][j+coins[i]] + dp[i+1][j];
                    } else {
                        dp[i][j] = dp[i][j+coins[i]];
                    }
                } 
            }
        }

        return dp[0][0];

    }
};

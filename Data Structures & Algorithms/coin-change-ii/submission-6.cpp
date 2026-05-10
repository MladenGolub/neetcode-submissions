class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp1(amount+1, 0);
        vector<int> dp2(amount+1, 0);

        dp1[amount] = 1;
        dp2[amount] = 1;

        sort(coins.begin(), coins.end());

        for(int i = coins.size() - 1; i >= 0; i--) {
            for(int j = amount-1; j >= 0; j--) {
                if((amount - j) - coins[i] >= 0) {
                    if(i+1 < coins.size()) {
                        dp1[j] = dp1[j+coins[i]] + dp2[j];
                    } else {
                        dp1[j] = dp1[j+coins[i]];
                    }
                } 
            }
            dp2 = dp1;
            dp1.assign(amount+1, 0);
            dp1[amount] = 1;
        }

        return dp2[0];

    }
};

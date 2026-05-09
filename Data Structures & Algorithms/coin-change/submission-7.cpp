class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        //for(int i = 0; i < coins.size(); i++) dp[coins[i]] = 1;//ako moze vrednost trenutna da se dobije samo od jednog novcica upisujemo 1

        for(int i = 1; i <= amount; i++) {
            //if(dp[i] != 1) {
                for(int j = 0; j< coins.size(); j++) {
                    if(coins[j] <= i) {//ako je trenutni amount veci ili jednak od novcica proveravamo da li mozemo da dobijemo amount preko drugih novcica
                        dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                    }
                }
            //} 
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

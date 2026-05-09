class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, -1);

        dp[0] = 0;//ako nam je amount 0 za taj target nam treba 0 novcica

        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] < dp.size()) dp[coins[i]] = 1;//ako novcic posotji u nizu, onda taj target mozemo da dobijemo samo preko 1 novcica
        }

        for(int i = 1; i < dp.size(); i++) {
            if(dp[i] != 1) {//ako je dp od i jednak 1 to znaci da mozemo da ga dobijemo samo jednim novcicem, to smo vec upisali u dp
                for(int j = 0; j < coins.size(); j++) {
                    if(i-coins[j] > 0 && dp[i-coins[j]] != -1) {//ako nas prethodnik moze da se dobije nekom kombinacijom probacemo da li mi mozemo da se dobijemo nekako
                        int pom = 1 + dp[i-coins[j]];
                        if(dp[i] > 0) dp[i] = min(dp[i], pom); 
                        else dp[i] = pom;
                    }
                }
            }
        }

        return dp[amount];

    }
};

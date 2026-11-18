class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MIN);

        dp[n] = 0;

        for(int i = n-1; i >= 0; i--) {
            int suma = 0;
            //dp[i] = INT_MIN;
            for(int k = 1; k < 4 && i + k <= n; k++) {
                suma += stoneValue[i + k - 1];
                dp[i] = max(dp[i], suma - dp[i + k]);
            }
        }        

        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";

    }
};
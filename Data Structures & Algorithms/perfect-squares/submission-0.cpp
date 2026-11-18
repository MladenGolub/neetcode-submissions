class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;

        vector<int> kvadrati;

        for(int i = 1; i*i <= n; i++) {
            kvadrati.push_back(i*i);
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < kvadrati.size(); j++) {
                if(kvadrati[j] <= i) {
                    dp[i] = min(dp[i], dp[i-kvadrati[j]] + 1);
                }
            }
        }

        return dp[n];

    }
};
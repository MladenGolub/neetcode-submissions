class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size() + 1, 0);
        int n = cost.size();
        dp[n-1] = cost[n-1]; 
        for(int i = n-2; i >= 0; i--) {
            dp[i] = min(cost[i] + dp[i+1], cost[i] + dp[i+2]);
        }

        return min(dp[0], dp[1]);

    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int total = accumulate(stones.begin(), stones.end(), 0);
        
        int half = total / 2;

        vector<bool> dp(half + 1, false);
        dp[0] = true;

        for(int s : stones) {
            for(int sum = half; sum >= s; sum--) {
                if(dp[sum - s]) dp[sum] = true; 
            }
        }

        for(int s = half; s >= 0; s--) {
            if(dp[s]) return total - 2 * s;
        }

        return 0;

    }
};
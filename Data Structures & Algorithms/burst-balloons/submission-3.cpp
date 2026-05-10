class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        vector<int> novi(nums.size()+2, 1);

        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size()+2, -1));

        for(int i = 0; i < nums.size(); i++) {
            novi[i+1] = nums[i];
        }

        return dfs(novi, 1, novi.size()-2, dp);

    }

    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {

        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        dp[l][r] = 0;

        for(int i = l; i <= r; i++) {
            int coins = nums[l-1] * nums[i] * nums[r+1];//ako racunamo da iti elemnt uzimamo kao poslednji, to izracunamo, a to ce uvek biti 1 * nums[i] * 1

            coins += dfs(nums, l, i-1, dp) + dfs(nums, i+1, r, dp);
            dp[l][r] = max(dp[l][r], coins);
        }

        return dp[l][r];

    }
};

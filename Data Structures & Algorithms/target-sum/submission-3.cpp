class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(totalSum * 2 + 1, 0));//sve stavimo na 0

        target = target + totalSum;

        dp[nums.size()][target] = 1;

        for(int i = nums.size()-1; i>=0; i--) {
            for(int j = 0; j <= totalSum*2; j++) {
                if(j >= nums[i] && j + nums[i] <= totalSum*2) {
                    dp[i][j] = dp[i+1][j-nums[i]] + dp[i+1][j+nums[i]];
                } else if(j >= nums[i]) {
                    dp[i][j] = dp[i+1][j-nums[i]];
                } else {
                    dp[i][j] = dp[i+1][j+nums[i]];
                }
            }
        }

        return dp[0][totalSum];

    }
};

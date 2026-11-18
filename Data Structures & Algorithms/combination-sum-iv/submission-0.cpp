class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<int> dp(target + 1, 0);

        dp[0] = 1;//postoji samo 1 nacin da se dobije 0, ne uzmemo nista

        for(int i = 0; i <= target; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[j] <= i) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];

    }
};
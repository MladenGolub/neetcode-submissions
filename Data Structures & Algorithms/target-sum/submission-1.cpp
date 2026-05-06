class Solution {

    vector<vector<int>> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        return dfs(0, 0, target, nums);//krecemo sa indeksom 0 i sa sumom 0
    }

    int dfs(int i, int sum, int &target, vector<int>& nums) {
        if(i == nums.size()) {
            if(sum == target) return true;
            else return false;
        }

        if(dp[i][sum + totalSum] != INT_MIN) return dp[i][sum + totalSum];

        dp[i][sum + totalSum] = dfs(i+1, sum + nums[i], target, nums) + dfs(i+1, sum - nums[i], target, nums);
        
        return dp[i][sum+totalSum];

    }
};

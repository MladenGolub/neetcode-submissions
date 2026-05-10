class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp1(totalSum * 2 + 1, 0);
        vector<int> dp2(totalSum * 2 + 1, 0);

        target = target + totalSum;

        dp2[target] = 1;

        for(int i = nums.size()-1; i>=0; i--) {
            for(int j = 0; j <= totalSum*2; j++) {
                if(j >= nums[i] && j + nums[i] <= totalSum*2) {
                    dp1[j] = dp2[j-nums[i]] + dp2[j+nums[i]];
                } else if(j >= nums[i]) {
                    dp1[j] = dp2[j-nums[i]];
                } else {
                    dp1[j] = dp2[j+nums[i]];
                }
            }
            dp2 = dp1;
            dp1.assign(totalSum * 2 + 1, 0);
        }

        return dp2[totalSum];

    }
};

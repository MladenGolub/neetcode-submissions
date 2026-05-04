class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
    vector<int> dp(nums.size(), 1);

    dp[nums.size()-1] = 1;

    for(int i = nums.size()-1; i >= 0; i--) {
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[i] < nums[j]) dp[i] = max(dp[i], 1+dp[j]);
        }
    }         

    int maxL = 0;
    for(int i = 0; i < dp.size(); i++) {
        if(dp[i] > maxL) maxL = dp[i];
    }

    return maxL;

    }
};

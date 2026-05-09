class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum+= nums[i];
        }

        if(sum % 2) return false;//ako je suma neparna, ne mozemo da podelimo niz

        vector<int> dp(nums.size(), 0);

        for(int i = nums.size()-2; i >= 0; i--) {
            dp[i] = dp[i+1] + nums[i+1];
        }

        for(int i = 0; i < nums.size(); i++) {
            int tr = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == sum/2) {
                    return true;
                }
                if(nums[i] + dp[j] == sum/2) {
                    return true;
                }
                if(tr + nums[j] < sum/2) {
                    tr += nums[j];
                    if(tr + nums[j+1] == sum/2) {
                        return true;
                    }
                    if(tr + dp[j+1] == sum/2) {
                        return true;
                    }
                }
            }
        }

        return false;

    }
};

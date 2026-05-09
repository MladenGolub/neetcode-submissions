class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //zelim da sacuvam u pomocnom nizu za svaku lokaciju, koliko nakon mene ima striktno vecih brojeva od mene
        vector<int> dp(nums.size(), 1);

        for(int i = nums.size()-1; i>=0; i--) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] < nums[j]) dp[i] = max(dp[i], 1+dp[j]);
            } 
        }

        int maxS = 0;

        for(int i = 0; i < dp.size(); i++) {
            if(dp[i] > maxS) maxS = dp[i];
        }

        return maxS;

    }
};

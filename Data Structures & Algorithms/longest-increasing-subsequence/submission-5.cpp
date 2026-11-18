class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n, 1);//svaki sam za sebe cini jedan takav niz
        
        for(int i = n-1; i>=0; i--) {
            for(int j = i + 1; j< n; j++) {
                if(nums[i] < nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] > res) res = dp[i];
        }

        return res;


    }
};

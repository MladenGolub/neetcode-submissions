class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> pom1(nums.begin(), nums.end() - 1);

        int prvi = robSingle(pom1);

        vector<int> pom2(nums.begin() + 1, nums.end());

        int poslednji = robSingle(pom2);

        return (prvi >= poslednji) ? prvi : poslednji;

    }

    int robSingle(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, 0);

        dp[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }

        return dp[0];
        
    }
};

class Solution {

    int cnt = 0;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        dfs(0, 0, target, nums);//krecemo sa indeksom 0 i sa sumom 0
        return cnt;
    }

    void dfs(int i, int sum, int &target, vector<int>& nums) {
        if(sum == target && i == nums.size()) this->cnt++;

        if(i >= nums.size()) return;
    
        dfs(i+1, sum+nums[i], target, nums);
        dfs(i+1, sum-nums[i], target, nums);
    }
};

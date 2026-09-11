class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        std::sort(nums.begin(), nums.end());
        dfs(0, curr, 0, target, res, nums);
        return res;
    }

    private:
    void dfs(int i, vector<int>& curr, int suma, int t, vector<vector<int>>& res, vector<int>& nums) {
        if (suma == t) {
            res.push_back(curr);
            return;
        }
        if(i >= nums.size() || suma > t) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(i+1, curr, suma + nums[i], t, res, nums);
        curr.pop_back();
        int j = i;
        while(j<nums.size() && nums[j] == nums[i]) j++;
        dfs(j, curr, suma, t, res, nums);
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
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
        dfs(i, curr, suma + nums[i], t, res, nums);
        curr.pop_back();
        dfs(i + 1, curr, suma, t, res, nums);
    }
};

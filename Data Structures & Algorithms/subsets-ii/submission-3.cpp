class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;

        sort(nums.begin(), nums.end());

        dfs(nums, 0, cur, ret);
        return ret;
    }

    void dfs(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& ret) {
        if(i >= nums.size()) {
            ret.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur, ret);
        cur.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }

        dfs(nums, i+1, cur, ret);
    }
};

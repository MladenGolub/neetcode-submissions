class Solution {

    vector<vector<int>> res;

    void backtrack(int start, vector<int>& nums) {
        if(start == nums.size()) {
            this->res.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[start] == nums[i]) continue;
            swap(nums[start], nums[i]);
            backtrack(start+1, nums);
        }

        for(int j = nums.size() - 1; j > start; j--) {
            swap(nums[start], nums[j]);
        }
        
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        backtrack(0, nums);

        return res;
    }
};
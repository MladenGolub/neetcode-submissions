class Solution {

private:

    vector<bool> used;


public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % k) return false;

        int target = totalSum / k;

        used = vector<bool>(nums.size(), false);

        return backtrack(0, nums, target, 0, k);

    }

    bool backtrack(int i, vector<int>& nums, int target, int trSum, int cnt) {
        
        if(cnt == 0) {
            return true;
        }

        if(trSum == target) {
            return backtrack(0, nums, target, 0, cnt - 1);
        }

        for(int j = i; j < nums.size(); j++) {
            if(used[j] || trSum + nums[j] > target) continue;
            used[j] = true;
            if(backtrack(j, nums, target, trSum + nums[j], cnt)) return true;
            used[j] = false;
        }

        return false;
    }
};
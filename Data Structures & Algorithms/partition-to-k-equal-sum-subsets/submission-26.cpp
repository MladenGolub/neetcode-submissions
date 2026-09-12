class Solution {

    vector<bool> used;

    bool backtrack(int i, int cnt, int trSum, int target, vector<int>& nums) {

        if(cnt == 0) {
            return true;
        }
        if(trSum == target) {
            return backtrack(0, cnt - 1, 0, target, nums);
        }

        for(int j = i; j < nums.size(); j++) {
            if(used[j] || trSum + nums[j] > target) continue;
            used[j] = true;
            if(backtrack(j + 1, cnt, trSum + nums[j], target, nums)) return true;
            used[j] = false; 
        }

        return false;

    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % k) return false;

        int target = totalSum / k;

        used = vector<bool>(nums.size(), false);

        return backtrack(0, k, 0, target, nums);

    }
};
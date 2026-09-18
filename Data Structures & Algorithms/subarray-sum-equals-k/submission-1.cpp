class Solution {
public:

    void backtrack(vector<int>& nums, int k, int trSum, int i, int& cnt) {
        if(i >= nums.size()) {    
            if(trSum == k) {
                cnt++;
            }
            return;
        }

        if(trSum == k) {
            cnt++;
        }

        backtrack(nums, k, trSum + nums[i], i + 1, cnt);

    }

    int subarraySum(vector<int>& nums, int k) {
        
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            backtrack(nums, k, nums[i], i + 1, cnt);
        }

        return cnt;

    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            if(val > 0 && val <= nums.size()) {
                if(nums[val - 1] > 0) {
                    nums[val - 1] *= -1;
                } else if(nums[val - 1] == 0) {
                    nums[val-1] = -1 * (nums.size());
                }
            }
        }

        int j = 0;

        for(; j < nums.size(); j++) {
            if(nums[j] >= 0) {
                return j + 1;
            }
        }

        return j+1;

    }
};
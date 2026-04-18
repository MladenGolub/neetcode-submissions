class Solution {
public:
    int rob(vector<int>& nums) {
        
        int pom = 0;

        if(nums.size() == 1) {
            return nums[0];
        }

        for(int i = nums.size()-1; i >= 0; i--) {
            if(i == nums.size()-1 || i == nums.size()-2) {
                continue;
            } else {
                pom = nums[i+1];
                nums[i] = (nums[i] + nums[i+2] >= pom) ? nums[i] + nums[i+2] : pom;
            }
            
        }

        return (nums[0] >= nums[1])? nums[0] : nums[1];

    }
};

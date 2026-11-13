class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int ukPro = 1;
        int numZ = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                numZ++;
            }
            ukPro *= (nums[i] != 0) ? nums[i] : 1;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                if(numZ > 0) {
                    nums[i] = 0;
                } else {
                    nums[i] = ukPro / nums[i];
                }
            } else {
                if(numZ <= 1) {
                    nums[i] = ukPro;
                } else if(numZ > 1) {
                    nums[i] = 0;
                }
            }
        }

        return nums;

    }
};

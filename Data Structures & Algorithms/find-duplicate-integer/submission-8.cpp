class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            int pom = nums[i];
            if(nums[abs(pom)] < 0) {
                return abs(pom);
            }
            nums[abs(pom)] *= -1;
        }

        return -1;

    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size();

        // if(target < nums[0]) return 0;
        // if(target > nums[nums.size()-1]) return nums.size();
 
        while(l < r) {
            if(nums[(l + r) / 2] < target) {
                l = (l + r) / 2 + 1;
            } else {
                r = (l + r) / 2;
            }
        }

        return l;

    }
};
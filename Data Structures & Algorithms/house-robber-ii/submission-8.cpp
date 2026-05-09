class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];

        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int levi = robSingle(vector<int>(nums.begin() + 1, nums.end()));
        int desni = robSingle(vector<int>(nums.begin(), nums.end()-1));


        return max(levi, desni);
    }

    int robSingle(vector<int>&& nums) {
        
        int rob1 = 0;
        int rob2 = 0;

        for (int num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;

    }
};

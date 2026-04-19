class Solution {
public:
    int rob(vector<int>& nums) {
        int levi = 0;
        int desni = 0;
    
        for(int i = 0; i<nums.size(); i++) {
            int curr = max(levi + nums[i], desni);
            levi = desni;
            desni = curr;
        }

        return desni;
    }
};

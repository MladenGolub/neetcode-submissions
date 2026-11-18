class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        int sumNiza = 0;

        for(int i = 0; i < nums.size(); i++) {
            sumNiza += nums[i];
        }

        return n*(n+1)/2 - sumNiza;

    }
};

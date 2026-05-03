class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxN = 1;
        int minN = 1;
        int res = nums[0];
        
        for(auto& num: nums) {
            int tmp = maxN * num;
            maxN = max(max(num * maxN, num * minN), num);
            minN = min(min(tmp, num * minN), num);
            res = max(res, maxN);
        }

        return res;

    }
};

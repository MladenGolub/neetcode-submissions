class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n*2, 0);

        for(int i = 0; i < n; i++) {
            ret[i] = nums[i];
            ret[i + n] = nums[i];
        }

        return ret;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> pom(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            pom[(i + k) % nums.size()] = nums[i];
        }

        for(int i = 0; i < pom.size(); i++) {
            nums[i] = pom[i];
        }
    }
};
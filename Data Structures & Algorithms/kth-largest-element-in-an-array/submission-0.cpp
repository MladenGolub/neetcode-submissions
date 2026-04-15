class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int i = 1;
        for(auto it = nums.rbegin(); it != nums.rend(); it++) {
            if(i < k) {
                i++;
                continue;
            } else {
                return *it;
            }
        }

    }
};

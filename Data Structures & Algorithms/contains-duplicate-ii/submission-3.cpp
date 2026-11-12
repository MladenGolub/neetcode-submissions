class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> mapa;

        for(int i = 0; i < nums.size(); i++) {
            if(mapa.find(nums[i]) != mapa.end() && i - mapa[nums[i]] <= k) {
                return true;
            } 
            mapa[nums[i]] = i;
        }

        return false;

    }
};
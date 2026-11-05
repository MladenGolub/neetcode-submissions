#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> brojevi;
        for(int i = 0; i < nums.size(); i++) {
            if(brojevi.find(nums[i]) == brojevi.end()) {
                brojevi.insert(nums[i]);
            } else {
                return true;
            }
        }     
        return false;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> cntMapa;

        for(int i = 0; i < nums.size(); i++) {
            cntMapa[nums[i]] += 1;
        }      

        vector<int> ret;

        for(auto it : cntMapa) {
            if(it.second > nums.size() / 3) {
                ret.push_back(it.first);
            }
        }

        return ret;

    }
};
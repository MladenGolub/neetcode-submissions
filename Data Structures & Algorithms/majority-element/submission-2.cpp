class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        unordered_map<int, int> brojac;

        for(int i = 0; i < nums.size(); i++) {
            if(brojac.find(nums[i]) == brojac.end()) {
                brojac[nums[i]] = 0;
            } else {
                brojac[nums[i]]++;
            }
        }
        int ret = 0;
        int maxCnt = 0;
        for(pair<int,int> node : brojac) {
            if(node.second > maxCnt) {
                maxCnt = node.second;
                ret = node.first;
            } 
        }

        return ret;

    }
};
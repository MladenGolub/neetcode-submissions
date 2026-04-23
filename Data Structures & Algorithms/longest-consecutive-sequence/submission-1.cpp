class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;
        
        std::sort(nums.begin(), nums.end());
        int cnt = 1;
        int maxCnt = -2;
        int trenutni = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == trenutni+1) {
                cnt++;
                trenutni = nums[i];
            } else if(nums[i] == trenutni) {
                continue;
            } else {
                if(cnt >= maxCnt) maxCnt = cnt;
                cnt = 1;
                trenutni = nums[i];
            }
        }

        if(cnt >= maxCnt) maxCnt = cnt;

        return maxCnt;

    }
};

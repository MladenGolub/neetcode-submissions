class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> skup(nums.begin(), nums.end());

        int maxCnt = 0;

        for(int x : skup) {

            if(!skup.count(x - 1)) {
                int curr = x;
                int cnt = 1;

                while(skup.count(curr+1)) {
                    curr++;
                    cnt++;
                }

                maxCnt = max(maxCnt, cnt);
            }

        }

        return maxCnt;

    }
};

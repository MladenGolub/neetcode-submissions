class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> skup(nums.begin(), nums.end());
        int maxCnt = 0;
        for(int x : skup) {
            
           

            if(!skup.count(x-1)) {//ako ne postoji neko za jedan manji od nas mi smo pocetak sekvence

                int cnt = 1;
                int curr = x;

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
